cmake_minimum_required(VERSION 3.24)

project(Lab VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if (DEFINED LABS_OVERRIDE)
    set(LAB_NUM ${LABS_OVERRIDE})

    message(STATUS "Lab number overridden; using ${LAB_NUM}")
else()
    file(GLOB LABS bachelor/sem1/informatics/*)
    list(GET LABS -1 LAST_LAB)

    string(REGEX MATCH "lab([0-9]+)$" _ "${LAST_LAB}")
    set(LAB_NUM ${CMAKE_MATCH_1})

    message(STATUS "Using the latest lab number (${LAB_NUM})")
endif()

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "bachelor/sem1/informatics/lab${LAB_NUM}/src/*.cpp")
add_executable(${PROJECT_NAME} ${SOURCES})

include(cmake/resolve-includes.cmake)