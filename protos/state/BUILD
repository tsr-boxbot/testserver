load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_compile", "cpp_grpc_library", "cpp_proto_compile")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

proto_library(
    name = "slot_state_proto",
    srcs = ["slot_state.proto"],
    deps = ["//protos/common:slot_address_proto", "//protos/common:package_meta_data_proto"],
    visibility = ["//visibility:public"],
)

proto_library(
    name = "tree_state_proto",
    srcs = ["tree_state.proto"],
    deps = ["//protos/common:slot_address_proto", "//protos/common:tree_meta_data_proto", "//protos/state:slot_state_proto"],
    visibility = ["//visibility:public"],
)
