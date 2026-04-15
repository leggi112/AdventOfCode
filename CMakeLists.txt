cmake_minimum_required(VERSION 3.25)
project(AdventOfCode LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

include(cmake/compiler_warnings.cmake)

add_subdirectory(aoc_utils)

# Autodiscover years
file(GLOB YEAR_DIRS RELATIVE ${CMAKE_SOURCE_DIR} "AoC[0-9][0-9]")

set(ALL_AOC_DAY_LIBS "")

set(GLOBAL_ALL_DAY_LIBS "")

foreach(YEAR ${YEAR_DIRS})
    if (IS_DIRECTORY "${CMAKE_SOURCE_DIR}/${YEAR}")
        message(STATUS "Found AoC year ${YEAR}")
        add_subdirectory(${YEAR})

        # Inhalt der Variable aus dem Subdirectory holen
        list(APPEND GLOBAL_ALL_DAY_LIBS ${${YEAR}_ALL_DAY_LIBS})
    endif()
endforeach()

# global main
file(GLOB_RECURSE ALL_RUNNER_SRCS CONFIGURE_DEPENDS "*main.cpp")
add_executable(aoc_all main.cpp)

# Link all libs
target_link_libraries(aoc_all PRIVATE ${GLOBAL_ALL_DAY_LIBS})

# auto add new days
function(add_aoc_day YEAR DAY)
    set(target aoc_${YEAR}_day${DAY})
    add_executable(${target}
	    AoC${YEAR}/day_${DAY}/main.cpp
    )
    target_link_libraries(${target} PRIVATE aoc_utils)
endfunction()
