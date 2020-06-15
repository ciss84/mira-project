/* Generated by the protocol buffer compiler.  DO NOT EDIT! */
/* Generated from: external/rpc.proto */

#ifndef PROTOBUF_C_external_2frpc_2eproto__INCLUDED
#define PROTOBUF_C_external_2frpc_2eproto__INCLUDED

#include <protobuf-c/protobuf-c.h>

PROTOBUF_C__BEGIN_DECLS

#if PROTOBUF_C_VERSION_NUMBER < 1000000
# error This file was generated by a newer version of protoc-c which is incompatible with your libprotobuf-c headers. Please update your headers.
#elif 1002001 < PROTOBUF_C_MIN_COMPILER_VERSION
# error This file was generated by an older version of protoc-c which is incompatible with your libprotobuf-c headers. Please regenerate this file with a newer version of protoc-c.
#endif


typedef struct _RpcHeader RpcHeader;
typedef struct _RpcTransport RpcTransport;


/* --- enums --- */

typedef enum _RpcCategory {
  RPC_CATEGORY__NONE = 0,
  RPC_CATEGORY__SYSTEM = 1,
  RPC_CATEGORY__LOG = 2,
  RPC_CATEGORY__DEBUG = 3,
  RPC_CATEGORY__FILE = 4,
  RPC_CATEGORY__COMMAND = 5,
  RPC_CATEGORY__MAX = 6
    PROTOBUF_C__FORCE_ENUM_TO_BE_INT_SIZE(RPC_CATEGORY)
} RpcCategory;

/* --- messages --- */

struct  _RpcHeader
{
  ProtobufCMessage base;
  protobuf_c_boolean has_magic;
  uint32_t magic;
  protobuf_c_boolean has_category;
  RpcCategory category;
  protobuf_c_boolean has_type;
  uint32_t type;
  protobuf_c_boolean has_error;
  int64_t error;
  protobuf_c_boolean has_isrequest;
  protobuf_c_boolean isrequest;
};
#define RPC_HEADER__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&rpc_header__descriptor) \
    , 0,0, 0,0, 0,0, 0,0, 0,0 }


struct  _RpcTransport
{
  ProtobufCMessage base;
  RpcHeader *header;
  protobuf_c_boolean has_data;
  ProtobufCBinaryData data;
};
#define RPC_TRANSPORT__INIT \
 { PROTOBUF_C_MESSAGE_INIT (&rpc_transport__descriptor) \
    , NULL, 0,{0,NULL} }


/* RpcHeader methods */
void   rpc_header__init
                     (RpcHeader         *message);
size_t rpc_header__get_packed_size
                     (const RpcHeader   *message);
size_t rpc_header__pack
                     (const RpcHeader   *message,
                      uint8_t             *out);
size_t rpc_header__pack_to_buffer
                     (const RpcHeader   *message,
                      ProtobufCBuffer     *buffer);
RpcHeader *
       rpc_header__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   rpc_header__free_unpacked
                     (RpcHeader *message,
                      ProtobufCAllocator *allocator);
/* RpcTransport methods */
void   rpc_transport__init
                     (RpcTransport         *message);
size_t rpc_transport__get_packed_size
                     (const RpcTransport   *message);
size_t rpc_transport__pack
                     (const RpcTransport   *message,
                      uint8_t             *out);
size_t rpc_transport__pack_to_buffer
                     (const RpcTransport   *message,
                      ProtobufCBuffer     *buffer);
RpcTransport *
       rpc_transport__unpack
                     (ProtobufCAllocator  *allocator,
                      size_t               len,
                      const uint8_t       *data);
void   rpc_transport__free_unpacked
                     (RpcTransport *message,
                      ProtobufCAllocator *allocator);
/* --- per-message closures --- */

typedef void (*RpcHeader_Closure)
                 (const RpcHeader *message,
                  void *closure_data);
typedef void (*RpcTransport_Closure)
                 (const RpcTransport *message,
                  void *closure_data);

/* --- services --- */


/* --- descriptors --- */

extern const ProtobufCEnumDescriptor    rpc_category__descriptor;
extern const ProtobufCMessageDescriptor rpc_header__descriptor;
extern const ProtobufCMessageDescriptor rpc_transport__descriptor;

PROTOBUF_C__END_DECLS


#endif  /* PROTOBUF_C_external_2frpc_2eproto__INCLUDED */
