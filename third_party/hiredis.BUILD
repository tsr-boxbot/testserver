package(default_visibility = ["//visibility:public"])

cc_library(
    name = "hiredis",
    srcs = [
        "hiredis.so",
    ],
    hdrs = [
        "hiredis.h",
        "read.h",
        "sds.h",
    ],
    include_prefix = "hiredis",
)

cc_library(
    name = "hiredis.so",
    srcs = [
        "async.c",
        "async.h",
        "async_private.h",
        "dict.c",
        "dict.h",
        "fmacros.h",
        "hiredis.c",
        "hiredis.h",
        "hiredis_ssl.h",
        "net.c",
        "net.h",
        "read.c",
        "read.h",
        "sds.c",
        "sds.h",
        "sdsalloc.h",
        "sockcompat.c",
        "sockcompat.h",
        "ssl.c",
        "win32.h",
    ],
    hdrs = [
        "async.h",
        "async_private.h",
        "dict.c",
        "dict.h",
        "fmacros.h",
        "hiredis.h",
        "hiredis_ssl.h",
        "net.h",
        "read.h",
        "sds.h",
        "sdsalloc.h",
        "sockcompat.h",
        "win32.h",
    ],
    copts = [
        "-Wno-unused-function",
        "-Wno-unused-variable",
    ],
    defines = ["USE_OPENSSL=1"],
    deps = [
        "@openssl//:crypto",
        "@openssl//:ssl",
    ],
)
