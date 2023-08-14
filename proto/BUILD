load("@rules_proto_grpc//cpp:defs.bzl", "cpp_grpc_compile", "cpp_grpc_library", "cpp_proto_compile")
load("@rules_proto//proto:defs.bzl", "proto_library")

package(default_visibility = ["//visibility:public"])

cpp_proto_compile(
    name = "testserver_cpp_proto",
    protos = ["testserver_proto"],
)

cpp_grpc_compile(
    name = "testserver_cpp_grpc",
    protos = ["testserver_proto"],
)

proto_library(
    name = "testserver_proto",
    srcs = ["testserver.proto"],
    visibility = ["//visibility:public"],
)

cpp_grpc_library(
    name = "testserver_cpp_grpc_lib",
    protos = ["testserver_proto"],
)
