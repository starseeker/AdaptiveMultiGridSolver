cmake_minimum_required(VERSION 3.12)

project(AMGS VERSION 13.61.0 LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
include(RPath_Setup)
cmake_set_rpath()

include(Path_Setup)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(BUILD_APPS "Build applications" ON)
option(BIG_DATA "Supports processing requiring more than 32-bit integers for indexing" OFF)
option(FAST_COMPILE "If enabled, only a single version of the code is compiled" OFF)
option(SHOW_WARNINGS "Display compilation warnings" OFF)
option(ARRAY_DEBUG "If enabled, array access is tested for validity" OFF)
option(USE_SEG_FAULT_HANDLER "Tries to dump a stack trace in the case of a segfault (gcc only)" OFF)

if(BIG_DATA)
  add_definitions(-DBIG_DATA_SET)
endif()

if(FAST_COMPILE)
  add_definitions(-DFAST_COMPILE_SET)
endif()

if(SHOW_WARNINGS)
  add_definitions(-DSHOW_WARNINGS_SET)
endif()

if(ARRAY_DEBUG)
  add_definitions(-DARRAY_DEBUG_SET)
endif()

if(USE_SEG_FAULT_HANDLER)
  add_definitions(-DUSE_SEG_FAULT_HANDLER_SET)
endif()

# Find required packages
if(BUILD_APPS)
	find_package(ZLIB REQUIRED)
	find_package(JPEG REQUIRED)
	find_package(PNG REQUIRED)
endif()

# gcc options
if(${CMAKE_CXX_COMPILER_ID} STREQUAL GNU)
add_compile_options("-O3;-pthread")
add_link_options("-pthread")
endif()

# msvc options
if(${CMAKE_CXX_COMPILER_ID} STREQUAL MSVC)
add_compile_options("/O2;/bigobj")
endif()

# clang options
if(${CMAKE_CXX_COMPILER_ID} STREQUAL Clang OR ${CMAKE_CXX_COMPILER_ID} STREQUAL AppleClang)
add_compile_options("-O3")
endif()

if (NOT DEFINED BIN_DIR)
	set(BIN_DIR bin)
endif (NOT DEFINED BIN_DIR)

add_subdirectory(src)

message(WARNING "\nCAUTION:  it is not recommended that users compile this code in parallel unless your machine has a VERY large amount of RAM.  (16GiB was not enough in a September 2020 test.)")

