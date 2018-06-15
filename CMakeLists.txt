cmake_minimum_required(VERSION 3.9)
project(leistungsnachweis-hornet)

include(ExternalProject)
ExternalProject_Add(gtest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG release-1.8.0
        PREFIX ${CMAKE_CURRENT_BINARY_DIR}/gtest
        INSTALL_COMMAND ""
        )

ExternalProject_Get_Property(gtest SOURCE_DIR BINARY_DIR)
set(GTEST_SOURCE_DIR ${SOURCE_DIR})
set(GTEST_BINARY_DIR ${BINARY_DIR})

set(CMAKE_CXX_STANDARD 11)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(leistungsnachweis-hornet main.cpp graph/ColorGraph.cpp graph/ColorGraph.h)

add_subdirectory(test)
