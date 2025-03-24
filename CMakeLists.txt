cmake_minimum_required(VERSION 3.31)
project(stl_threads C CXX)

include(FetchContent)
FetchContent_Declare(setup_gtest GIT_REPOSITORY https://github.com/CesarBerriot/setup_gtest.git GIT_TAG 1.2.0)
FetchContent_Declare(discover_sources GIT_REPOSITORY https://github.com/CesarBerriot/discover_sources.git GIT_TAG 1.0.0)
FetchContent_MakeAvailable(setup_gtest discover_sources)
include(${setup_gtest_SOURCE_DIR}/setup_gtest.cmake)
include(${discover_sources_SOURCE_DIR}/discover_sources.cmake)

add_library(stl_threads)
discover_sources(stl_threads)
target_include_directories(stl_threads PUBLIC include PRIVATE source)

if(${BUILD_TESTING})
    setup_gtest(stl_threads)
endif()
