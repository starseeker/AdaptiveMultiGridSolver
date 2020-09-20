set(AMGS_IO_SOURCES  include/amgs_io/Ply.h
                     include/amgs_io/Ply.inl
                     include/amgs_io/PlyFile.h
                     include/amgs_io/PlyFile.inl
                     include/amgs_io/VertexFactory.h
                     include/amgs_io/VertexFactory.inl
                     include/amgs_io/VertexStreamImpl.h
                     include/amgs_io/VertexStreamImpl.inl
)

add_library(amgs_io INTERFACE)
target_sources(amgs_io INTERFACE ${AMGS_IO_SOURCES})
target_include_directories(amgs_io INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> "${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries(amgs_io INTERFACE)

add_library(amgs_io::amgs_io ALIAS amgs_io)

install(TARGETS amgs_io
      INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(FILES ${AMGS_IO_SOURCES}
         DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/amgs_io
)

# Custom target used to display this header only library in IDEs 
add_custom_target(AdaptiveMultiGridSolverIO SOURCES ${AMGS_IO_SOURCES})

