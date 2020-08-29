cmake_minimum_required(VERSION 3.17)

# Use ccache if available
find_program(CCACHE_PROGRAM ccache)
if(CCACHE_PROGRAM)
    set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE "${CCACHE_PROGRAM}")
endif()

project(AdaptiveFiniteElementSolver VERSION 13.5.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(BUILD_APPS "Build applications" ON)
option(PRECOMPILED_HEADERS "Use precompiled headers for building the applications" OFF)

set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

if(APPLE)
  set(basePoint @loader_path)
else()
  set(basePoint $ORIGIN)
endif()

include(GNUInstallDirs)
file(RELATIVE_PATH relDir
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}
  ${CMAKE_CURRENT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})

set(CMAKE_INSTALL_RPATH ${basePoint} ${basePoint}/${relDir})

# Find required packages
include(cmake/find_dependencies.cmake REQUIREED)
# Setup compiler
include(cmake/compiler_options.cmake REQUIRED)


add_subdirectory(src)
