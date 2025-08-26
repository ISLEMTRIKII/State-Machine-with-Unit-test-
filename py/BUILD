py_binary(
    name = "helper_main",
    srcs = ["helper_main.py"],
)

py_binary(
    name = "bank_account_main",
    srcs = ["bank_account_main.py"],
)

py_library(
    name = "helper_lib",
    srcs = ["helper_main.py"],  # use helper_main.py
    visibility = ["//visibility:public"],
)

py_library(
    name = "bank_account_lib",
    srcs = ["bank_account_main.py"],  # use bank_account_main.py
    visibility = ["//visibility:public"],
)

py_test(
    name = "test_helper",
    srcs = ["test_helper.py"],
    deps = [":helper_lib"],
)

py_test(
    name = "test_bank_account",
    srcs = ["test_bank_account.py"],
    deps = [":bank_account_lib"],  # updated
)
