#ifndef CBOR_OBJECT_H_
#define CBOR_OBJECT_H_

#include "ArduinoCbor.h"

class CborObject {
 friend class CborVariant;

 public:
  CborObject(CborBuffer& buffer, cn_cbor* raw=0);

  CborVariant get(const char* key);
  CborVariant get(const int8_t key);

  void set(const char* key, CborVariant value);
  void set(const char* key, const char* value);
  void set(const char* key, CBOR_INT_T value);
  void set(const char* key, CborObject value);
  void set(const char* key, CborArray value);

  void set(const int8_t key, CborVariant value);
  void set(const int8_t key, const char* value);
  void set(const int8_t key, CBOR_INT_T value);
  void set(const int8_t key, CborObject value);
  void set(const int8_t key, CborArray value);

  size_t encode(uint8_t* data, size_t size);

 protected:
  CborBuffer& buffer;
  cn_cbor* raw;
};

#endif // CBOR_OBJECT_H_
