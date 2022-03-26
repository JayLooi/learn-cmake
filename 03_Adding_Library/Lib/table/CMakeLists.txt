add_library(Table STATIC)

target_sources(
    Table
    PRIVATE
        src/Table.cpp
)

target_include_directories(
    Table
    PUBLIC
        "include"
)
