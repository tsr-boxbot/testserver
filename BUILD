load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake", "configure_make")
load("@rules_pkg//:pkg.bzl", "pkg_deb", "pkg_tar")

package(default_visibility = ["//visibility:public"])

cc_binary(
    name = "testserver",
    srcs = [
        "main.cc",
    ],
    deps = [
    ],
)

buildifier(
    name = "buildifier",
)
