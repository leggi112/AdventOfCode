# Name des Jahresordners automatisch bestimmen
get_filename_component(YEAR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

message(STATUS "Configuring ${YEAR_NAME}")

# -------------------------------------------------
# Alle Day Ordner automatisch finden
# -------------------------------------------------
file(GLOB DAY_DIRS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} "day_*")

set(ALL_DAY_LIBS "")

foreach(DAY ${DAY_DIRS})
    if(IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/${DAY}")
        message(STATUS "  Found ${YEAR_NAME}/${DAY}")

        # day_01 -> aoc_AoC25_day_01
        set(DAY_TARGET aoc_${YEAR_NAME}_${DAY})

        add_library(${DAY_TARGET}
            ${DAY}/${DAY}.cpp
        )

        target_include_directories(${DAY_TARGET}
            PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
        )

        target_link_libraries(${DAY_TARGET}
            PUBLIC aoc_utils
        )

        list(APPEND ALL_DAY_LIBS ${DAY_TARGET})
    endif()
endforeach()

# -------------------------------------------------
# Year Library (aggregiert alle Tage)
# -------------------------------------------------
set(YEAR_TARGET aoc_${YEAR_NAME})

add_library(${YEAR_TARGET}
    year.cpp
)

target_include_directories(${YEAR_TARGET}
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(${YEAR_TARGET}
    PUBLIC
        aoc_utils
        ${ALL_DAY_LIBS}
)

# -------------------------------------------------
# Export zurück an Root CMake
# -------------------------------------------------
set(${YEAR_NAME}_ALL_DAY_LIBS ${YEAR_TARGET} PARENT_SCOPE)
