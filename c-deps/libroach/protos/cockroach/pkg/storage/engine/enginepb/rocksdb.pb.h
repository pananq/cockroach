// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cockroach/pkg/storage/engine/enginepb/rocksdb.proto

#ifndef PROTOBUF_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto__INCLUDED
#define PROTOBUF_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3003000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3003002 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/message_lite.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include "cockroach/pkg/util/hlc/timestamp.pb.h"
// @@protoc_insertion_point(includes)
namespace cockroach {
namespace storage {
namespace engine {
namespace enginepb {
class SSTUserProperties;
class SSTUserPropertiesDefaultTypeInternal;
extern SSTUserPropertiesDefaultTypeInternal _SSTUserProperties_default_instance_;
class SSTUserPropertiesCollection;
class SSTUserPropertiesCollectionDefaultTypeInternal;
extern SSTUserPropertiesCollectionDefaultTypeInternal _SSTUserPropertiesCollection_default_instance_;
}  // namespace enginepb
}  // namespace engine
}  // namespace storage
namespace util {
namespace hlc {
class Timestamp;
class TimestampDefaultTypeInternal;
extern TimestampDefaultTypeInternal _Timestamp_default_instance_;
}  // namespace hlc
}  // namespace util
}  // namespace cockroach

namespace cockroach {
namespace storage {
namespace engine {
namespace enginepb {

namespace protobuf_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto {
// Internal implementation detail -- do not call these.
struct TableStruct {
  static const ::google::protobuf::internal::ParseTableField entries[];
  static const ::google::protobuf::internal::AuxillaryParseTableField aux[];
  static const ::google::protobuf::internal::ParseTable schema[];
  static const ::google::protobuf::uint32 offsets[];
  static void InitDefaultsImpl();
  static void Shutdown();
};
void AddDescriptors();
void InitDefaults();
}  // namespace protobuf_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto

// ===================================================================

class SSTUserProperties : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:cockroach.storage.engine.enginepb.SSTUserProperties) */ {
 public:
  SSTUserProperties();
  virtual ~SSTUserProperties();

  SSTUserProperties(const SSTUserProperties& from);

  inline SSTUserProperties& operator=(const SSTUserProperties& from) {
    CopyFrom(from);
    return *this;
  }

  static const SSTUserProperties& default_instance();

  static inline const SSTUserProperties* internal_default_instance() {
    return reinterpret_cast<const SSTUserProperties*>(
               &_SSTUserProperties_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    0;

  void Swap(SSTUserProperties* other);

  // implements Message ----------------------------------------------

  inline SSTUserProperties* New() const PROTOBUF_FINAL { return New(NULL); }

  SSTUserProperties* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const SSTUserProperties& from);
  void MergeFrom(const SSTUserProperties& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SSTUserProperties* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string path = 1;
  void clear_path();
  static const int kPathFieldNumber = 1;
  const ::std::string& path() const;
  void set_path(const ::std::string& value);
  #if LANG_CXX11
  void set_path(::std::string&& value);
  #endif
  void set_path(const char* value);
  void set_path(const char* value, size_t size);
  ::std::string* mutable_path();
  ::std::string* release_path();
  void set_allocated_path(::std::string* path);

  // .cockroach.util.hlc.Timestamp ts_min = 2;
  bool has_ts_min() const;
  void clear_ts_min();
  static const int kTsMinFieldNumber = 2;
  const ::cockroach::util::hlc::Timestamp& ts_min() const;
  ::cockroach::util::hlc::Timestamp* mutable_ts_min();
  ::cockroach::util::hlc::Timestamp* release_ts_min();
  void set_allocated_ts_min(::cockroach::util::hlc::Timestamp* ts_min);

  // .cockroach.util.hlc.Timestamp ts_max = 3;
  bool has_ts_max() const;
  void clear_ts_max();
  static const int kTsMaxFieldNumber = 3;
  const ::cockroach::util::hlc::Timestamp& ts_max() const;
  ::cockroach::util::hlc::Timestamp* mutable_ts_max();
  ::cockroach::util::hlc::Timestamp* release_ts_max();
  void set_allocated_ts_max(::cockroach::util::hlc::Timestamp* ts_max);

  // @@protoc_insertion_point(class_scope:cockroach.storage.engine.enginepb.SSTUserProperties)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::internal::ArenaStringPtr path_;
  ::cockroach::util::hlc::Timestamp* ts_min_;
  ::cockroach::util::hlc::Timestamp* ts_max_;
  mutable int _cached_size_;
  friend struct protobuf_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto::TableStruct;
};
// -------------------------------------------------------------------

class SSTUserPropertiesCollection : public ::google::protobuf::MessageLite /* @@protoc_insertion_point(class_definition:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection) */ {
 public:
  SSTUserPropertiesCollection();
  virtual ~SSTUserPropertiesCollection();

  SSTUserPropertiesCollection(const SSTUserPropertiesCollection& from);

  inline SSTUserPropertiesCollection& operator=(const SSTUserPropertiesCollection& from) {
    CopyFrom(from);
    return *this;
  }

  static const SSTUserPropertiesCollection& default_instance();

  static inline const SSTUserPropertiesCollection* internal_default_instance() {
    return reinterpret_cast<const SSTUserPropertiesCollection*>(
               &_SSTUserPropertiesCollection_default_instance_);
  }
  static PROTOBUF_CONSTEXPR int const kIndexInFileMessages =
    1;

  void Swap(SSTUserPropertiesCollection* other);

  // implements Message ----------------------------------------------

  inline SSTUserPropertiesCollection* New() const PROTOBUF_FINAL { return New(NULL); }

  SSTUserPropertiesCollection* New(::google::protobuf::Arena* arena) const PROTOBUF_FINAL;
  void CheckTypeAndMergeFrom(const ::google::protobuf::MessageLite& from)
    PROTOBUF_FINAL;
  void CopyFrom(const SSTUserPropertiesCollection& from);
  void MergeFrom(const SSTUserPropertiesCollection& from);
  void Clear() PROTOBUF_FINAL;
  bool IsInitialized() const PROTOBUF_FINAL;

  size_t ByteSizeLong() const PROTOBUF_FINAL;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input) PROTOBUF_FINAL;
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const PROTOBUF_FINAL;
  void DiscardUnknownFields();
  int GetCachedSize() const PROTOBUF_FINAL { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(SSTUserPropertiesCollection* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return NULL;
  }
  inline void* MaybeArenaPtr() const {
    return NULL;
  }
  public:

  ::std::string GetTypeName() const PROTOBUF_FINAL;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  int sst_size() const;
  void clear_sst();
  static const int kSstFieldNumber = 1;
  const ::cockroach::storage::engine::enginepb::SSTUserProperties& sst(int index) const;
  ::cockroach::storage::engine::enginepb::SSTUserProperties* mutable_sst(int index);
  ::cockroach::storage::engine::enginepb::SSTUserProperties* add_sst();
  ::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::SSTUserProperties >*
      mutable_sst();
  const ::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::SSTUserProperties >&
      sst() const;

  // string error = 2;
  void clear_error();
  static const int kErrorFieldNumber = 2;
  const ::std::string& error() const;
  void set_error(const ::std::string& value);
  #if LANG_CXX11
  void set_error(::std::string&& value);
  #endif
  void set_error(const char* value);
  void set_error(const char* value, size_t size);
  ::std::string* mutable_error();
  ::std::string* release_error();
  void set_allocated_error(::std::string* error);

  // @@protoc_insertion_point(class_scope:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection)
 private:

  ::google::protobuf::internal::InternalMetadataWithArenaLite _internal_metadata_;
  ::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::SSTUserProperties > sst_;
  ::google::protobuf::internal::ArenaStringPtr error_;
  mutable int _cached_size_;
  friend struct protobuf_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto::TableStruct;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// SSTUserProperties

// string path = 1;
inline void SSTUserProperties::clear_path() {
  path_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SSTUserProperties::path() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.SSTUserProperties.path)
  return path_.GetNoArena();
}
inline void SSTUserProperties::set_path(const ::std::string& value) {
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:cockroach.storage.engine.enginepb.SSTUserProperties.path)
}
#if LANG_CXX11
inline void SSTUserProperties::set_path(::std::string&& value) {
  
  path_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:cockroach.storage.engine.enginepb.SSTUserProperties.path)
}
#endif
inline void SSTUserProperties::set_path(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cockroach.storage.engine.enginepb.SSTUserProperties.path)
}
inline void SSTUserProperties::set_path(const char* value, size_t size) {
  
  path_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cockroach.storage.engine.enginepb.SSTUserProperties.path)
}
inline ::std::string* SSTUserProperties::mutable_path() {
  
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.SSTUserProperties.path)
  return path_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SSTUserProperties::release_path() {
  // @@protoc_insertion_point(field_release:cockroach.storage.engine.enginepb.SSTUserProperties.path)
  
  return path_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SSTUserProperties::set_allocated_path(::std::string* path) {
  if (path != NULL) {
    
  } else {
    
  }
  path_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), path);
  // @@protoc_insertion_point(field_set_allocated:cockroach.storage.engine.enginepb.SSTUserProperties.path)
}

// .cockroach.util.hlc.Timestamp ts_min = 2;
inline bool SSTUserProperties::has_ts_min() const {
  return this != internal_default_instance() && ts_min_ != NULL;
}
inline void SSTUserProperties::clear_ts_min() {
  if (GetArenaNoVirtual() == NULL && ts_min_ != NULL) delete ts_min_;
  ts_min_ = NULL;
}
inline const ::cockroach::util::hlc::Timestamp& SSTUserProperties::ts_min() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.SSTUserProperties.ts_min)
  return ts_min_ != NULL ? *ts_min_
                         : *::cockroach::util::hlc::Timestamp::internal_default_instance();
}
inline ::cockroach::util::hlc::Timestamp* SSTUserProperties::mutable_ts_min() {
  
  if (ts_min_ == NULL) {
    ts_min_ = new ::cockroach::util::hlc::Timestamp;
  }
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.SSTUserProperties.ts_min)
  return ts_min_;
}
inline ::cockroach::util::hlc::Timestamp* SSTUserProperties::release_ts_min() {
  // @@protoc_insertion_point(field_release:cockroach.storage.engine.enginepb.SSTUserProperties.ts_min)
  
  ::cockroach::util::hlc::Timestamp* temp = ts_min_;
  ts_min_ = NULL;
  return temp;
}
inline void SSTUserProperties::set_allocated_ts_min(::cockroach::util::hlc::Timestamp* ts_min) {
  delete ts_min_;
  ts_min_ = ts_min;
  if (ts_min) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:cockroach.storage.engine.enginepb.SSTUserProperties.ts_min)
}

// .cockroach.util.hlc.Timestamp ts_max = 3;
inline bool SSTUserProperties::has_ts_max() const {
  return this != internal_default_instance() && ts_max_ != NULL;
}
inline void SSTUserProperties::clear_ts_max() {
  if (GetArenaNoVirtual() == NULL && ts_max_ != NULL) delete ts_max_;
  ts_max_ = NULL;
}
inline const ::cockroach::util::hlc::Timestamp& SSTUserProperties::ts_max() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.SSTUserProperties.ts_max)
  return ts_max_ != NULL ? *ts_max_
                         : *::cockroach::util::hlc::Timestamp::internal_default_instance();
}
inline ::cockroach::util::hlc::Timestamp* SSTUserProperties::mutable_ts_max() {
  
  if (ts_max_ == NULL) {
    ts_max_ = new ::cockroach::util::hlc::Timestamp;
  }
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.SSTUserProperties.ts_max)
  return ts_max_;
}
inline ::cockroach::util::hlc::Timestamp* SSTUserProperties::release_ts_max() {
  // @@protoc_insertion_point(field_release:cockroach.storage.engine.enginepb.SSTUserProperties.ts_max)
  
  ::cockroach::util::hlc::Timestamp* temp = ts_max_;
  ts_max_ = NULL;
  return temp;
}
inline void SSTUserProperties::set_allocated_ts_max(::cockroach::util::hlc::Timestamp* ts_max) {
  delete ts_max_;
  ts_max_ = ts_max;
  if (ts_max) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:cockroach.storage.engine.enginepb.SSTUserProperties.ts_max)
}

// -------------------------------------------------------------------

// SSTUserPropertiesCollection

inline int SSTUserPropertiesCollection::sst_size() const {
  return sst_.size();
}
inline void SSTUserPropertiesCollection::clear_sst() {
  sst_.Clear();
}
inline const ::cockroach::storage::engine::enginepb::SSTUserProperties& SSTUserPropertiesCollection::sst(int index) const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.sst)
  return sst_.Get(index);
}
inline ::cockroach::storage::engine::enginepb::SSTUserProperties* SSTUserPropertiesCollection::mutable_sst(int index) {
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.sst)
  return sst_.Mutable(index);
}
inline ::cockroach::storage::engine::enginepb::SSTUserProperties* SSTUserPropertiesCollection::add_sst() {
  // @@protoc_insertion_point(field_add:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.sst)
  return sst_.Add();
}
inline ::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::SSTUserProperties >*
SSTUserPropertiesCollection::mutable_sst() {
  // @@protoc_insertion_point(field_mutable_list:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.sst)
  return &sst_;
}
inline const ::google::protobuf::RepeatedPtrField< ::cockroach::storage::engine::enginepb::SSTUserProperties >&
SSTUserPropertiesCollection::sst() const {
  // @@protoc_insertion_point(field_list:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.sst)
  return sst_;
}

// string error = 2;
inline void SSTUserPropertiesCollection::clear_error() {
  error_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline const ::std::string& SSTUserPropertiesCollection::error() const {
  // @@protoc_insertion_point(field_get:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
  return error_.GetNoArena();
}
inline void SSTUserPropertiesCollection::set_error(const ::std::string& value) {
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
}
#if LANG_CXX11
inline void SSTUserPropertiesCollection::set_error(::std::string&& value) {
  
  error_.SetNoArena(
    &::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
}
#endif
inline void SSTUserPropertiesCollection::set_error(const char* value) {
  GOOGLE_DCHECK(value != NULL);
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
}
inline void SSTUserPropertiesCollection::set_error(const char* value, size_t size) {
  
  error_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
}
inline ::std::string* SSTUserPropertiesCollection::mutable_error() {
  
  // @@protoc_insertion_point(field_mutable:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
  return error_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline ::std::string* SSTUserPropertiesCollection::release_error() {
  // @@protoc_insertion_point(field_release:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
  
  return error_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
inline void SSTUserPropertiesCollection::set_allocated_error(::std::string* error) {
  if (error != NULL) {
    
  } else {
    
  }
  error_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), error);
  // @@protoc_insertion_point(field_set_allocated:cockroach.storage.engine.enginepb.SSTUserPropertiesCollection.error)
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)


}  // namespace enginepb
}  // namespace engine
}  // namespace storage
}  // namespace cockroach

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_cockroach_2fpkg_2fstorage_2fengine_2fenginepb_2frocksdb_2eproto__INCLUDED
