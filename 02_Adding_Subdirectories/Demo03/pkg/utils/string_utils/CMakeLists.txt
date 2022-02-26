target_sources(
    ${CMAKE_PROJECT_NAME}
    PRIVATE
        src/string_utils.cpp
)

target_include_directories(
    ${CMAKE_PROJECT_NAME}
    PRIVATE
        "include"
)