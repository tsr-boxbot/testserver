load("@com_github_bazelbuild_buildtools//buildifier:def.bzl", "buildifier")
load("@rules_foreign_cc//foreign_cc:defs.bzl", "cmake", "configure_make")
load("@rules_pkg//:pkg.bzl", "pkg_deb", "pkg_tar")

package(default_visibility = ["//visibility:public"])

exports_files(["CPPLINT.cfg"])

buildifier(
    name = "buildifier",
)

cmake(
    name = "paho-mqtt-c",
    cache_entries = {
        "PAHO_BUILD_SHARED": "False",
        "PAHO_BUILD_STATIC": "True",
        "PAHO_WITH_SSL": "True",
        "PAHO_HIGH_PERFORMANCE": "True",
        "PAHO_ENABLE_TESTING": "False",
    },
    lib_source = "@paho-mqtt-c//:all",
    out_static_libs = ["libpaho-mqtt3a.a"],
    deps = [
        "@openssl//:crypto",
        "@openssl//:ssl",
    ],
)

cmake(
    name = "paho-mqtt-cpp",
    cache_entries = {
        "PAHO_BUILD_SHARED": "False",
        "PAHO_BUILD_STATIC": "True",
        "PAHO_WITH_SSL": "True",
        "PAHO_MQTT_C_LIBRARIES": "${EXT_BUILD_DEPS}/paho-mqtt-c/lib",
        "PAHO_MQTT_C_INCLUDE_DIRS": "${EXT_BUILD_DEPS}/paho-mqtt-c/include",
    },
    lib_source = "@paho-mqtt-cpp//:all",
    out_static_libs = ["libpaho-mqttpp3.a"],
    deps = [
        ":paho-mqtt-c",
        "@openssl//:crypto",
        "@openssl//:ssl",
    ],
)

cc_binary(
    name = "simple_mqtt",
    srcs = glob([
        "simple_mqtt.cc",
    ]),
    deps = [
        "//:paho-mqtt-cpp",
    ],
)

cc_binary(
    name = "recv",
    srcs = glob([
        "recv.cpp",
    ]),
    deps = [
        "//protos:testserver_cpp_grpc_lib",
        "//:paho-mqtt-cpp",
    ],
)

cc_binary(
    name = "testserver",
    deps = [
        "//:main",
        "//:inmemory_database",
        "//:mqtt_announcer",
    ],
)

cc_library(
    name = "main",
    srcs = glob([
        "main.cc",
    ]),
    deps = [
        "//:paho-mqtt-cpp",
        "//protos:testserver_cpp_grpc_lib",
        "//:database",
        "//:announcer",
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
    name = "announcer",
    srcs = glob([
        "announcer.h",
    ]),
    hdrs = glob([
        "announcer.h",
    ]),
    deps = [
        "//protos:testserver_cpp_grpc_lib",
    ],
)

cc_library(
    name = "mqtt_announcer",
    srcs = glob([
        "mqtt_announcer.cpp",
    ]),
    deps = [
        "//protos:testserver_cpp_grpc_lib",
        '//:announcer',
        "//:paho-mqtt-cpp",
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
