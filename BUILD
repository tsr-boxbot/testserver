load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake", "configure_make")
load("@rules_pkg//:pkg.bzl", "pkg_deb", "pkg_tar")
load("@rules_cc//cc:defs.bzl", "cc_binary")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "testserver",
    srcs = [
        "main.cc",
    ],
    deps = [
        "//:redis_database",
        "//protos:testserver_cpp_grpc_lib",
        "//:database",
    ],
)

cc_binary(
    name = "testserver2",
    srcs = [
        "main.cc",
    ],
    deps = [
        "//:inmemory_database",
        "//protos:testserver_cpp_grpc_lib",
        "//:database",
    ],
)

cc_binary(
    name = "client",
    srcs = ["client.cc"],
    linkopts = ["-ldl"],
    deps = [
        "//protos:testserver_cpp_grpc_lib",
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
    ],
)

cc_library(
    name = "database",
    srcs = glob([
        "database.h",
    ]),
    hdrs = glob([
        "database.h",
    ]),
    deps = [
        "//protos:testserver_cpp_grpc_lib",
    ],
)

cc_library(
    name = "redis_database",
    srcs = glob([
        "redis.cc",
    ]),
    deps = [
        "@redis",
        "//:database",
        "//protos:testserver_cpp_grpc_lib",
    ],
)

cc_library(
    name = "inmemory_database",
    srcs = glob([
        "inmemory.cc",
    ]),
    deps = [
        "//:database",
        "//protos:testserver_cpp_grpc_lib",
    ],
)

buildifier(
    name = "buildifier",
)
