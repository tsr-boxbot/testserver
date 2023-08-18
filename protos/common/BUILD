load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_compile", "cpp_grpc_library", "cpp_proto_compile")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

proto_library(
    name = "slot_address_proto",
    srcs = ["slot_address.proto"],
    visibility = ["//visibility:public"],
)

proto_library(
    name = "package_meta_data_proto",
    srcs = ["package_meta_data.proto"],
    visibility = ["//visibility:public"],
)

proto_library(
    name = "tree_meta_data_proto",
    srcs = ["tree_meta_data.proto"],
    visibility = ["//visibility:public"],
)
