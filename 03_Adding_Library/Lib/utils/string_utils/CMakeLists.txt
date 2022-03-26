add_library(string_utils STATIC)

target_sources(
    string_utils
    PRIVATE
        src/string_utils.cpp
)

target_include_directories(
    string_utils
    PUBLIC
        "include"
)
