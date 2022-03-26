add_library(simple_argparse STATIC)

target_sources(
    simple_argparse
    PRIVATE
        src/simple_argparse.cpp
)

target_include_directories(
    simple_argparse
    PUBLIC
        "include"
)

target_link_libraries(simple_argparse PRIVATE string_utils)
