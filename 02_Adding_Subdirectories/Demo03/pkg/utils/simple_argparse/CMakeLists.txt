target_sources(
    ${CMAKE_PROJECT_NAME}
    PRIVATE
        src/simple_argparse.cpp
)

target_include_directories(
    ${CMAKE_PROJECT_NAME}
    PRIVATE
        "include"
)