// Copyright 2015 The Cockroach Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or
// implied. See the License for the specific language governing
// permissions and limitations under the License.

// This code was derived from https://github.com/youtube/vitess.
//
// Copyright 2012, Google Inc. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file

package parser

import (
	"bytes"
	"fmt"
	"unicode/utf8"
)

var (
	dontEscape = byte(255)
	// encodeMap specifies how to escape binary data with '\'.
	encodeMap [256]byte
	// mustQuoteMap contains characters that require that their enclosing
	// string be quoted, even when FmtFlags.bareStrings is true.
	//
	// This is used e.g. when stringifying expressions with array types
	// for pgwire.
	mustQuoteMap = map[byte]bool{
		' ': true,
		',': true,
		'{': true,
		'}': true,
	}
	// hexMap is a mapping from each byte to the `\x%%` hex form as a []byte.
	hexMap [256][]byte
	// rawHexMap is a mapping from each byte to the `%%` hex form as a []byte.
	rawHexMap [256][]byte
)

// encodeSQLString writes a string literal to buf. All unicode and
// non-printable characters are escaped.
func encodeSQLString(buf *bytes.Buffer, in string) {
	encodeSQLStringWithFlags(buf, in, FmtSimple)
}

// EscapeSQLString returns an escaped SQL representation of the given
// string. This is suitable for safely producing a SQL string valid
// for input to the parser.
func EscapeSQLString(in string) string {
	var buf bytes.Buffer
	encodeSQLString(&buf, in)
	return buf.String()
}

func hexEncodeString(buf *bytes.Buffer, in string) {
	for i := 0; i < len(in); i++ {
		buf.Write(rawHexMap[in[i]])
	}
}

// encodeEscapedChar is used internally to write out a character from a larger
// string that needs to be escaped to a buffer.
func encodeEscapedChar(
	buf *bytes.Buffer,
	entireString string,
	currentRune rune,
	currentByte byte,
	currentIdx int,
	quoteChar byte,
) {
	ln := utf8.RuneLen(currentRune)
	if currentRune == utf8.RuneError {
		// Errors are due to invalid unicode points, so escape the bytes.
		// Make sure this is run at least once in case ln == -1.
		buf.Write(hexMap[entireString[currentIdx]])
		for ri := 1; ri < ln; ri++ {
			buf.Write(hexMap[entireString[currentIdx+ri]])
		}
	} else if ln == 1 {
		// For single-byte runes, do the same as encodeSQLBytes.
		if encodedChar := encodeMap[currentByte]; encodedChar != dontEscape {
			buf.WriteByte('\\')
			buf.WriteByte(encodedChar)
		} else if currentByte == quoteChar {
			buf.WriteByte('\\')
			buf.WriteByte(quoteChar)
		} else {
			// Escape non-printable characters.
			buf.Write(hexMap[currentByte])
		}
	} else if ln == 2 {
		// For multi-byte runes, print them based on their width.
		fmt.Fprintf(buf, `\u%04X`, currentRune)
	} else {
		fmt.Fprintf(buf, `\U%08X`, currentRune)
	}
}

// encodeSQLStringWithFlags writes a string literal to buf. All unicode and
// non-printable characters are escaped. FmtFlags controls the output format:
// if f.bareStrings is true, the output string will not be wrapped in quotes
// if the strings contains no special characters.
func encodeSQLStringWithFlags(buf *bytes.Buffer, in string, f FmtFlags) {
	// See http://www.postgresql.org/docs/9.4/static/sql-syntax-lexical.html
	start := 0
	escapedString := false
	bareStrings := f.bareStrings
	// Loop through each unicode code point.
	for i, r := range in {
		ch := byte(r)
		if r >= 0x20 && r < 0x7F {
			if mustQuoteMap[ch] {
				// We have to quote this string - ignore bareStrings setting
				bareStrings = false
			}
			if encodeMap[ch] == dontEscape && ch != '\'' {
				continue
			}
		}

		if !escapedString {
			buf.WriteString("e'") // begin e'xxx' string
			escapedString = true
		}
		buf.WriteString(in[start:i])
		ln := utf8.RuneLen(r)
		if ln < 0 {
			start = i + 1
		} else {
			start = i + ln
		}
		encodeEscapedChar(buf, in, r, ch, i, '\'')
	}

	quote := !escapedString && !bareStrings
	if quote {
		buf.WriteByte('\'') // begin 'xxx' string if nothing was escaped
	}
	buf.WriteString(in[start:])
	if escapedString || quote {
		buf.WriteByte('\'')
	}
}

// encodeSQLStringInsideArray writes a string literal to buf using the "string
// within array" formatting.
func encodeSQLStringInsideArray(buf *bytes.Buffer, in string) {
	buf.WriteByte('"')
	// Loop through each unicode code point.
	for i, r := range in {
		ch := byte(r)
		if r >= 0x20 && r < 0x7F && encodeMap[ch] == dontEscape && ch != '"' {
			// Character is printable doesn't need escaping - just print it out.
			buf.WriteByte(ch)
		} else {
			encodeEscapedChar(buf, in, r, ch, i, '"')
		}
	}

	buf.WriteByte('"')
}

func encodeSQLIdent(buf *bytes.Buffer, s string, f FmtFlags) {
	if isNonKeywordBareIdentifier(s) {
		buf.WriteString(s)
		return
	}

	// The only character that requires escaping is a double quote.
	if !f.bareIdentifiers {
		buf.WriteString(`"`)
	}
	start := 0
	for i, n := 0, len(s); i < n; i++ {
		ch := s[i]
		if ch == '"' {
			if start != i {
				buf.WriteString(s[start:i])
			}
			start = i + 1
			buf.WriteByte(ch)
			buf.WriteByte(ch) // add extra copy of ch
		}
	}
	if start < len(s) {
		buf.WriteString(s[start:])
	}
	if !f.bareIdentifiers {
		buf.WriteString(`"`)
	}
}

func encodeSQLBytes(buf *bytes.Buffer, in string) {
	start := 0
	buf.WriteString("b'")
	// Loop over the bytes of the string (i.e., don't use range over unicode
	// code points).
	for i, n := 0, len(in); i < n; i++ {
		ch := in[i]
		if encodedChar := encodeMap[ch]; encodedChar != dontEscape {
			buf.WriteString(in[start:i])
			buf.WriteByte('\\')
			buf.WriteByte(encodedChar)
			start = i + 1
		} else if ch == '\'' {
			// We can't just fold this into encodeMap because encodeMap is also used for strings which aren't quoted with single-quotes
			buf.WriteString(in[start:i])
			buf.WriteByte('\\')
			buf.WriteByte(ch)
			start = i + 1
		} else if ch < 0x20 || ch >= 0x7F {
			buf.WriteString(in[start:i])
			// Escape non-printable characters.
			buf.Write(hexMap[ch])
			start = i + 1
		}
	}
	buf.WriteString(in[start:])
	buf.WriteByte('\'')
}

func init() {
	encodeRef := map[byte]byte{
		'\b': 'b',
		'\f': 'f',
		'\n': 'n',
		'\r': 'r',
		'\t': 't',
		'\\': '\\',
	}

	for i := range encodeMap {
		encodeMap[i] = dontEscape
	}
	for i := range encodeMap {
		if to, ok := encodeRef[byte(i)]; ok {
			encodeMap[byte(i)] = to
		}
	}

	// underlyingHexMap contains the string "\x00\x01\x02..." which hexMap and
	// rawHexMap then index into.
	var underlyingHexMap bytes.Buffer
	underlyingHexMap.Grow(1024)

	for i := 0; i < 256; i++ {
		underlyingHexMap.WriteString("\\x")
		writeHexDigit(&underlyingHexMap, i/16)
		writeHexDigit(&underlyingHexMap, i%16)
	}

	underlyingHexBytes := underlyingHexMap.Bytes()

	for i := 0; i < 256; i++ {
		hexMap[i] = underlyingHexBytes[i*4 : i*4+4]
		rawHexMap[i] = underlyingHexBytes[i*4+2 : i*4+4]
	}
}

func writeHexDigit(buf *bytes.Buffer, v int) {
	if v < 10 {
		buf.WriteByte('0' + byte(v))
	} else {
		buf.WriteByte('a' + byte(v-10))
	}
}
