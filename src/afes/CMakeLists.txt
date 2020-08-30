set(AFES_SOURCES  include/afes/Allocator.h
                  include/afes/Array.h
                  include/afes/Array.inl
                  include/afes/BSplineData.h
                  include/afes/BSplineData.inl
                  include/afes/BinaryNode.h
                  include/afes/BlockedVector.h
                  include/afes/CoredMesh.h
                  include/afes/CoredMesh.inl
                  include/afes/FEMTree.Evaluation.inl
                  include/afes/FEMTree.Initialize.inl
                  include/afes/FEMTree.IsoSurface.specialized.inl
                  include/afes/FEMTree.SortedTreeNodes.inl
                  include/afes/FEMTree.System.inl
                  include/afes/FEMTree.WeightedSamples.inl
                  include/afes/FEMTree.h
                  include/afes/FEMTree.inl
                  include/afes/Factor.h
                  include/afes/FunctionData.h
                  include/afes/FunctionData.inl
                  include/afes/Geometry.h
                  include/afes/Geometry.inl
                  include/afes/LinearSolvers.h
                  include/afes/MAT.h
                  include/afes/MAT.inl
                  include/afes/MarchingCubes.h
                  include/afes/MyMiscellany.h
                  include/afes/PPolynomial.h
                  include/afes/PPolynomial.inl
                  include/afes/Polynomial.h
                  include/afes/Polynomial.inl
                  include/afes/PreProcessor.h
                  include/afes/Rasterizer.h
                  include/afes/Rasterizer.inl
                  include/afes/RegularGrid.h
                  include/afes/RegularGrid.inl
                  include/afes/RegularTree.h
                  include/afes/RegularTree.inl
                  include/afes/SparseMatrix.h
                  include/afes/SparseMatrix.inl
                  include/afes/SparseMatrixInterface.h
                  include/afes/SparseMatrixInterface.inl
                  include/afes/VertexStream.h
                  include/afes/Window.h
                  include/afes/Window.inl
)

add_library(afes INTERFACE)
target_sources(afes INTERFACE ${AFES_SOURCES})
target_include_directories(afes INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> "${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries(afes INTERFACE)

add_library(afes::afes ALIAS afes)

install(TARGETS afes
      INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(FILES ${AFES_SOURCES}
         DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/afes
)

# Custom target used to display this header only library in IDEs 
add_custom_target(AdaptiveFiniteElementSolver SOURCES ${AFES_SOURCES})

