# AdaptiveTreeVisualization 
add_executable(AdaptiveTreeVisualization AdaptiveTreeVisualization.cpp)
target_link_libraries(AdaptiveTreeVisualization afes::afes)
        
install(TARGETS AdaptiveTreeVisualization
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# ChunkPLY 
add_executable(ChunkPLY ChunkPLY.cpp)
target_link_libraries(ChunkPLY afes::afes)
        
install(TARGETS ChunkPLY
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# EDTInHeat 
add_executable(EDTInHeat EDTInHeat.cpp)
target_link_libraries(EDTInHeat afes::afes)
        
install(TARGETS EDTInHeat
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# ImageStitching 
add_executable(ImageStitching ImageStitching.cpp)
target_link_libraries(ImageStitching afes::afes)
        
install(TARGETS ImageStitching
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# PointInterpolant 
add_executable(PointInterpolant PointInterpolant.cpp)
target_link_libraries(PointInterpolant afes::afes)
        
install(TARGETS PointInterpolant
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# PoissonRecon 
add_executable(PoissonRecon PoissonRecon.cpp)
target_link_libraries(PoissonRecon afes::afes)

install(TARGETS PoissonRecon
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# SSDRecon 
add_executable(SSDRecon SSDRecon.cpp)
target_link_libraries(SSDRecon afes::afes)

install(TARGETS SSDRecon
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# SurfaceTrimmer 
add_executable(SurfaceTrimmer SurfaceTrimmer.cpp)
target_link_libraries(SurfaceTrimmer afes::afes)

install(TARGETS SurfaceTrimmer
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

if(PRECOMPILED_HEADERS)
target_precompile_headers(AdaptiveTreeVisualization
                        PRIVATE 
                        <afes/MyMiscellany.h>
                        <afes/CmdLineParser.h>
                        <afes/PPolynomial.h>
                        <afes/FEMTree.h>
                        <afes/Ply.h>
                        <afes/VertexFactory.h>
                        <afes/Image.h>
                        <afes/RegularGrid.h>
                        <afes/PreProcessor.h>)

target_precompile_headers (ChunkPLY REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (EDTInHeat REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (ImageStitching REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (PointInterpolant REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (PoissonRecon REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (SSDRecon REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (SurfaceTrimmer REUSE_FROM AdaptiveTreeVisualization)

endif()


