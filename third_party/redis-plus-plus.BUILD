load("@rules_cc//cc:defs.bzl", "cc_library")

package(default_visibility = ["//visibility:public"])

HDRS = [
    "command.h",
    "command_args.h",
    "command_options.h",
    "connection.h",
    "connection_pool.h",
    "errors.h",
    "pipeline.h",
    "queued_redis.h",
    "queued_redis.hpp",
    "redis++.h",
    "redis.h",
    "redis.hpp",
    "redis_cluster.h",
    "redis_cluster.hpp",
    "reply.h",
    "sentinel.h",
    "shards.h",
    "shards_pool.h",
    "subscriber.h",
    "transaction.h",
    "utils.h",
]

SRCS = [
    "command.cpp",
    "command_options.cpp",
    "connection.cpp",
    "connection_pool.cpp",
    "crc16.cpp",
    "errors.cpp",
    "pipeline.cpp",
    "redis.cpp",
    "redis_cluster.cpp",
    "reply.cpp",
    "sentinel.cpp",
    "shards.cpp",
    "shards_pool.cpp",
    "subscriber.cpp",
    "transaction.cpp",
]

cc_library(
    name = "redis",
    srcs = ["src/sw/redis++/{}".format(x) for x in SRCS] + ["src/sw/redis++/{}".format(x) for x in HDRS],
    hdrs = ["src/sw/redis++/{}".format(x) for x in HDRS],
    copts = ["-std=c++20"],
    strip_include_prefix = "src",
    deps = ["@hiredis"],
)
