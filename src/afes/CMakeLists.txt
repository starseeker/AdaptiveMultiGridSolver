add_library(afes INTERFACE)
target_include_directories(afes INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> "${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries(afes INTERFACE
                      zlib::zlib
                      libpng::libpng
                      libjpeg::libjpeg)
install(TARGETS afes
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

add_library(afes::afes ALIAS afes)

