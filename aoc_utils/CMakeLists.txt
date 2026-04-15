add_library(aoc_utils
    src/io.cpp
)

target_include_directories(aoc_utils
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_features(aoc_utils PUBLIC cxx_std_23)
set_project_warnings(aoc_utils)
