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
        "//proto:testserver_cpp_grpc_lib",
    ],
)

cc_binary(
    name = "client",
    srcs = ["client.cc"],
    linkopts = ["-ldl"],
    deps = [
        "//proto:testserver_cpp_grpc_lib",
        "@com_github_grpc_grpc//:grpc++",
        "@com_github_grpc_grpc//:grpc++_reflection",
    ],
)

buildifier(
    name = "buildifier",
)
