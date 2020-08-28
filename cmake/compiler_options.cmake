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