workspace(name = "testserver")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

# for CMAKE
all_content = """filegroup(name = "all", srcs = glob(["**"]), visibility = ["//visibility:public"])"""

# Rule repository
http_archive(
    name = "rules_foreign_cc",
    sha256 = "2a4d07cd64b0719b39a7c12218a3e507672b82a97b98c6a89d38565894cf7c51",
    strip_prefix = "rules_foreign_cc-0.9.0",
    url = "https://github.com/bazelbuild/rules_foreign_cc/archive/refs/tags/0.9.0.tar.gz",
)

load("@rules_foreign_cc//foreign_cc:repositories.bzl", "rules_foreign_cc_dependencies")

rules_foreign_cc_dependencies(register_default_tools = True)

# buildifier is written in Go and hence needs rules_go to be built.
# See https://github.com/bazelbuild/rules_go for the up to date setup instructions.
http_archive(
    name = "io_bazel_rules_go",
    sha256 = "d1ffd055969c8f8d431e2d439813e42326961d0942bdf734d2c95dc30c369566",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_go/releases/download/v0.24.5/rules_go-v0.24.5.tar.gz",
        "https://github.com/bazelbuild/rules_go/releases/download/v0.24.5/rules_go-v0.24.5.tar.gz",
    ],
)

load("@io_bazel_rules_go//go:deps.bzl", "go_register_toolchains", "go_rules_dependencies")

go_rules_dependencies()

go_register_toolchains()

http_archive(
    name = "bazel_gazelle",
    sha256 = "b85f48fa105c4403326e9525ad2b2cc437babaa6e15a3fc0b1dbab0ab064bc7c",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/bazel-gazelle/releases/download/v0.22.2/bazel-gazelle-v0.22.2.tar.gz",
        "https://github.com/bazelbuild/bazel-gazelle/releases/download/v0.22.2/bazel-gazelle-v0.22.2.tar.gz",
    ],
)

load("@bazel_gazelle//:deps.bzl", "gazelle_dependencies")

gazelle_dependencies()

http_archive(
    name = "com_google_protobuf",
    sha256 = "bf0e5070b4b99240183b29df78155eee335885e53a8af8683964579c214ad301",
    strip_prefix = "protobuf-3.14.0",
    urls = ["https://github.com/protocolbuffers/protobuf/archive/v3.14.0.zip"],
)

http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/d6fb5e3bf76c0363d7519373a07c2435e57c1073.zip"],
  sha256 = "7889ba028854b03e0a73d41b2ee6ede4f1a4ab100b18d18bda8488e5d751ba42",
  strip_prefix = "googletest-d6fb5e3bf76c0363d7519373a07c2435e57c1073",
)

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")

protobuf_deps()

http_archive(
    name = "com_github_bazelbuild_buildtools",
    strip_prefix = "buildtools-master",
    url = "https://github.com/bazelbuild/buildtools/archive/master.zip",
)

http_archive(
    name = "modbus",
    build_file_content = all_content,
    sha256 = "fe0c141cd10d58bb848643f00f2d4b4005214f93312d7b66ac805fd369876651",
    strip_prefix = "libmodbus-3.1.6",
    urls = ["https://github.com/stephane/libmodbus/archive/v3.1.6.tar.gz"],
)

http_archive(
    name = "paho-mqtt-cpp",
    build_file_content = all_content,
    sha256 = "435e97e4d5b1da13daa26cadd3e83fe9d154930abaa78b8ff1b8c854b5345d8b",
    strip_prefix = "paho.mqtt.cpp-1.2.0",
    urls = ["https://github.com/eclipse/paho.mqtt.cpp/archive/refs/tags/v1.2.0.tar.gz"],
)

http_archive(
    name = "paho-mqtt-c",
    build_file_content = all_content,
    sha256 = "386c9b5fa1cf6d0d516db12d57fd8f6a410dd0fdc5e9a2da870aae437a2535ed",
    strip_prefix = "paho.mqtt.c-1.3.9",
    patch_args = ["-p1"],
    patch_tool = "patch",
    patches = ["@//third_party:paho.mqtt.c.patch"],
    urls = ["https://github.com/eclipse/paho.mqtt.c/archive/refs/tags/v1.3.9.tar.gz"],
)

new_local_repository(
    name = "mosquitto",
    build_file = "third_party/mosquitto.BUILD",
    path = "/usr/lib/x86_64-linux-gnu",
)

new_local_repository(
    name = "mosquittopp",
    build_file = "third_party/mosquittopp.BUILD",
    path = "/usr/lib/x86_64-linux-gnu",
)

http_archive(
    name = "lcm",
    build_file = "@//third_party:lcm.BUILD",
    patch_args = ["-p1"],
    patch_tool = "patch",
    patches = ["@//third_party:lcm.patch"],
    sha256 = "61f9df86f2e1757e41fcab0f5579f39237d1b58810541063b830f77e2a3f4380",
    strip_prefix = "lcm-71c24268563d862d3435eeb6d2204deb766c0dd0",
    urls = ["https://github.com/lcm-proj/lcm/archive/71c24268563d862d3435eeb6d2204deb766c0dd0.tar.gz"],
)

# cpplint from google style guide
http_archive(
    name = "cpplint",
    build_file = "@//third_party:cpplint.BUILD",
    sha256 = "073e03302dd514b577fa2328cdbece10e7d2bdaab3ebbb1bb26f4e67f71a46ca",
    strip_prefix = "cpplint-e96032241aa33b5bd4464680462ccbb8239d1c72",
    urls = ["https://github.com/cpplint/cpplint/archive/e96032241aa33b5bd4464680462ccbb8239d1c72.tar.gz"],
)

# CLI11 (argument parsing)
http_archive(
    name = "cli11",
    build_file = "@//third_party:cli11.BUILD",
    sha256 = "f80d557738397f1e1cc434f3c3f41c828d8a95a81b77c147f88e9b98d638a692",
    strip_prefix = "CLI11-4b3a6b6214952f2d266959e79c285231f56eae74",
    urls = ["https://github.com/CLIUtils/CLI11/archive/4b3a6b6214952f2d266959e79c285231f56eae74.zip"],
)

http_archive(
    name = "nlohmann_json",
    build_file = "@//third_party:nlohmann_json.BUILD",
    sha256 = "e5c7a9f49a16814be27e4ed0ee900ecd0092bfb7dbfca65b5a421b774dccaaed",
    urls = ["https://github.com/nlohmann/json/releases/download/v3.11.2/include.zip"],
)

# hireds (redis client)
http_archive(
    name = "hiredis",
    build_file = "@//third_party:hiredis.BUILD",
    sha256 = "929cbd6036e93759378d976ef3c5e4a3b14ba8b15782b7d72a4ce62ab62f107f",
    strip_prefix = "hiredis-f2ef5f0c985a16c07ef610205f92864ac30c34dd",
    urls = ["https://github.com/redis/hiredis/archive/f2ef5f0c985a16c07ef610205f92864ac30c34dd.zip"],
)

http_archive(
    name = "redis",
    build_file = "@//third_party:redis-plus-plus.BUILD",
    sha256 = "33024eea63fd34e7dcc916e93c79a96bcff4a0254fc841ec2617c78a09e9b5b5",
    strip_prefix = "redis-plus-plus-a5c7c003111e679e44b3d531f05b73ce2ea1e8eb",
    urls = ["https://github.com/sewenew/redis-plus-plus/archive/a5c7c003111e679e44b3d531f05b73ce2ea1e8eb.zip"],
)

http_archive(
    name = "openssl",
    build_file = "@//third_party:openssl.BUILD",
    sha256 = "f56dd7d81ce8d3e395f83285bd700a1098ed5a4cb0a81ce9522e41e6db7e0389",
    strip_prefix = "openssl-OpenSSL_1_1_0h",
    url = "https://github.com/openssl/openssl/archive/OpenSSL_1_1_0h.tar.gz",
)

http_archive(
    name = "magic_enum",
    build_file = "@//third_party:magic_enum.BUILD",
    sha256 = "62bd7034bbbfc3d7806001767d5775ab42f3ff33bb38366e1ceb21102f0dff9a",
    strip_prefix = "magic_enum-0.8.2",
    urls = ["https://github.com/Neargye/magic_enum/archive/refs/tags/v0.8.2.tar.gz"],
)

http_archive(
    name = "pcre",
    build_file = "@//third_party:pcre.BUILD",
    sha256 = "4dae6fdcd2bb0bb6c37b5f97c33c2be954da743985369cddac3546e3218bffb8",
    strip_prefix = "pcre-8.45",
    urls = ["https://sourceforge.net/projects/pcre/files/pcre/8.45/pcre-8.45.tar.bz2"],
)

http_archive(
    name = "eipscanner",
    build_file_content = all_content,
    sha256 = "0eeccd98d45be79c607a5ca78d681ea7d19ded0bb615bcb9f3ca4b85c4332094",
    strip_prefix = "EIPScanner-1.3.0",
    urls = ["https://github.com/nimbuscontrols/EIPScanner/archive/refs/tags/1.3.0.tar.gz"],
    patch_args = ["-p1"],
    patch_tool = "patch",
    patches = ["@//third_party:eipscanner.patch"],
)

git_repository(
    name = "com_github_nelhage_rules_boost",
    commit = "fce83babe3f6287bccb45d2df013a309fa3194b8",
    remote = "https://github.com/nelhage/rules_boost",
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")

boost_deps()

# General packages
http_archive(
    name = "com_github_mjbots_bazel_deps",
    sha256 = "2e9bfa3f83c959316f6f2d3ab02cc7ab01cb917c21b10e94d62b4c475419d6af",
    strip_prefix = "bazel_deps-59b22fffdc250a5205bf47f9a0e9161c71f632a4",
    urls = ["https://github.com/mjbots/bazel_deps/archive/59b22fffdc250a5205bf47f9a0e9161c71f632a4.zip"],
)

load("@com_github_mjbots_bazel_deps//tools/workspace:default.bzl", "add_default_repositories")

# arguments are excluded
add_default_repositories([
    "boost",
    "pcre",
])

http_archive(
    name = "rules_proto",
    sha256 = "2490dca4f249b8a9a3ab07bd1ba6eca085aaf8e45a734af92aad0c42d9dc7aaf",
    strip_prefix = "rules_proto-218ffa7dfa5408492dc86c01ee637614f8695c45",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_proto/archive/218ffa7dfa5408492dc86c01ee637614f8695c45.tar.gz",
        "https://github.com/bazelbuild/rules_proto/archive/218ffa7dfa5408492dc86c01ee637614f8695c45.tar.gz",
    ],
)

git_repository(
    name = "com_github_grpc_grpc",
    patch_args = ["-p1"],
    patch_tool = "patch",
    patches = ["@//third_party:grpc.patch"],
    commit = "b0f37a22bbae12a4b225a88be6d18d5e41dce881",
    remote = "https://github.com/grpc/grpc",
)

http_archive(
    name = "rules_proto_grpc",
    sha256 = "507e38c8d95c7efa4f3b1c0595a8e8f139c885cb41a76cab7e20e4e67ae87731",
    strip_prefix = "rules_proto_grpc-4.1.1",
    urls = ["https://github.com/rules-proto-grpc/rules_proto_grpc/archive/4.1.1.tar.gz"],
)

load("@rules_proto_grpc//:repositories.bzl", "rules_proto_grpc_repos", "rules_proto_grpc_toolchains")

rules_proto_grpc_toolchains()

rules_proto_grpc_repos()

load("@rules_proto//proto:repositories.bzl", "rules_proto_dependencies", "rules_proto_toolchains")

rules_proto_dependencies()

rules_proto_toolchains()

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")

grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")

grpc_extra_deps()

load("@rules_proto_grpc//cpp:repositories.bzl", rules_proto_grpc_cpp_repos = "cpp_repos")

rules_proto_grpc_cpp_repos()

http_archive(
    name = "rules_pkg",
    sha256 = "62eeb544ff1ef41d786e329e1536c1d541bb9bcad27ae984d57f18f314018e66",
    urls = [
        "https://mirror.bazel.build/github.com/bazelbuild/rules_pkg/releases/download/0.6.0/rules_pkg-0.6.0.tar.gz",
        "https://github.com/bazelbuild/rules_pkg/releases/download/0.6.0/rules_pkg-0.6.0.tar.gz",
    ],
)

load("@rules_pkg//:deps.bzl", "rules_pkg_dependencies")

rules_pkg_dependencies()


http_archive(
    name = "pybind11_bazel",
    strip_prefix = "pybind11_bazel-b162c7c88a253e3f6b673df0c621aca27596ce6b",
    urls = [
        "https://github.com/pybind/pybind11_bazel/archive/b162c7c88a253e3f6b673df0c621aca27596ce6b.zip"
    ],
    sha256 = "b72c5b44135b90d1ffaba51e08240be0b91707ac60bea08bb4d84b47316211bb",
)

http_archive(
    name = "pybind11",
    strip_prefix = "pybind11-2.10.4",
    build_file = "@pybind11_bazel//:pybind11.BUILD",
    urls = [
        "https://github.com/pybind/pybind11/archive/refs/tags/v2.10.4.zip"
    ],
    sha256 = "115bc49b69133dd8a7a7f824b669826ff6a35bc70a28ce2cf987d57c50a6543a",
)
load("@pybind11_bazel//:python_configure.bzl", "python_configure")
python_configure(name = "local_config_python")

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
  name = "com_google_absl",
  urls = ["https://github.com/abseil/abseil-cpp/archive/98eb410c93ad059f9bba1bf43f5bb916fc92a5ea.zip"],
  strip_prefix = "abseil-cpp-98eb410c93ad059f9bba1bf43f5bb916fc92a5ea",
)

