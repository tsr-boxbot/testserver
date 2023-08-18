load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_compile", "cpp_grpc_library", "cpp_proto_compile")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

proto_library(
    name = "testserver_proto",
    srcs = ["testserver.proto"],
    deps = [
        "//protos/common:slot_address_proto",
        "//protos/common:tree_meta_data_proto",
        "//protos/state:slot_state_proto",
        "//protos/state:tree_state_proto"
    ],
    visibility = ["//visibility:public"],
)

cpp_grpc_library(
    name = "testserver_cpp_grpc_lib",
    protos = [
      "testserver_proto",
      "//protos/common:slot_address_proto",
      "//protos/common:tree_meta_data_proto",
      "//protos/common:package_meta_data_proto",
      "//protos/state:slot_state_proto",
      "//protos/state:tree_state_proto"
    ],
)
