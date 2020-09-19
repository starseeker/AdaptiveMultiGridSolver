set(AMGS_SOURCES  include/amgs/Allocator.h
                  include/amgs/Array.h
                  include/amgs/Array.inl
                  include/amgs/BSplineData.h
                  include/amgs/BSplineData.inl
                  include/amgs/BinaryNode.h
                  include/amgs/BlockedVector.h
                  include/amgs/CoredMesh.h
                  include/amgs/CoredMesh.inl
                  include/amgs/FEMTree.Evaluation.inl
                  include/amgs/FEMTree.Initialize.inl
                  include/amgs/FEMTree.IsoSurface.specialized.inl
                  include/amgs/FEMTree.SortedTreeNodes.inl
                  include/amgs/FEMTree.System.inl
                  include/amgs/FEMTree.WeightedSamples.inl
                  include/amgs/FEMTree.h
                  include/amgs/FEMTree.inl
                  include/amgs/Factor.h
                  include/amgs/FunctionData.h
                  include/amgs/FunctionData.inl
                  include/amgs/Geometry.h
                  include/amgs/Geometry.inl
                  include/amgs/LinearSolvers.h
                  include/amgs/MAT.h
                  include/amgs/MAT.inl
                  include/amgs/MarchingCubes.h
                  include/amgs/MyMiscellany.h
                  include/amgs/PPolynomial.h
                  include/amgs/PPolynomial.inl
                  include/amgs/Polynomial.h
                  include/amgs/Polynomial.inl
                  include/amgs/PreProcessor.h
                  include/amgs/Rasterizer.h
                  include/amgs/Rasterizer.inl
                  include/amgs/RegularGrid.h
                  include/amgs/RegularGrid.inl
                  include/amgs/RegularTree.h
                  include/amgs/RegularTree.inl
                  include/amgs/SparseMatrix.h
                  include/amgs/SparseMatrix.inl
                  include/amgs/SparseMatrixInterface.h
                  include/amgs/SparseMatrixInterface.inl
                  include/amgs/VertexStream.h
                  include/amgs/Window.h
                  include/amgs/Window.inl
)

add_library(amgs INTERFACE)
target_sources(amgs INTERFACE ${AMGS_SOURCES})
target_include_directories(amgs INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include> "${CMAKE_CURRENT_BINARY_DIR}")
target_link_libraries(amgs INTERFACE)

add_library(amgs::amgs ALIAS amgs)

install(TARGETS amgs
      INCLUDES
        DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
)
install(FILES ${AMGS_SOURCES}
         DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/amgs
)

# Custom target used to display this header only library in IDEs 
add_custom_target(AdaptiveMultiGridSolver SOURCES ${AMGS_SOURCES})

