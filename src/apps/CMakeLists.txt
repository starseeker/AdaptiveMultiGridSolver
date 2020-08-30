# AdaptiveTreeVisualization 
add_executable(AdaptiveTreeVisualization AdaptiveTreeVisualization.cpp)
target_link_libraries(AdaptiveTreeVisualization 
                       PRIVATE
                        afes::afes
                        apps_utils::apps_utils)
        
install(TARGETS AdaptiveTreeVisualization
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# ChunkPLY 
add_executable(ChunkPLY ChunkPLY.cpp)
target_link_libraries(ChunkPLY
                       PRIVATE
                        afes::afes
                        apps_utils::apps_utils)
        
install(TARGETS ChunkPLY
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# EDTInHeat 
add_executable(EDTInHeat EDTInHeat.cpp)
target_link_libraries(EDTInHeat
                      PRIVATE
                       afes::afes
                       apps_utils::apps_utils)
        
install(TARGETS EDTInHeat
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# ImageStitching 
add_executable(ImageStitching ImageStitching.cpp)
target_link_libraries(ImageStitching
                      PRIVATE
                       afes::afes
                       apps_utils::apps_utils)
        
install(TARGETS ImageStitching
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# PointInterpolant 
add_executable(PointInterpolant PointInterpolant.cpp)
target_link_libraries(PointInterpolant
                      PRIVATE
                       afes::afes
                       apps_utils::apps_utils)
        
install(TARGETS PointInterpolant
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# PoissonRecon 
add_executable(PoissonRecon PoissonRecon.cpp)
target_link_libraries(PoissonRecon
                      PRIVATE
                       afes::afes
                       apps_utils::apps_utils)

install(TARGETS PoissonRecon
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# SSDRecon 
add_executable(SSDRecon SSDRecon.cpp)
target_link_libraries(SSDRecon
                      PRIVATE
                       afes::afes
                       apps_utils::apps_utils)

install(TARGETS SSDRecon
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# SurfaceTrimmer 
add_executable(SurfaceTrimmer SurfaceTrimmer.cpp)
target_link_libraries(SurfaceTrimmer
                      PRIVATE
                       afes::afes
                       apps_utils::apps_utils)

install(TARGETS SurfaceTrimmer
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

if(PRECOMPILED_HEADERS)
target_precompile_headers(AdaptiveTreeVisualization
                        PRIVATE 
                        <afes/MyMiscellany.h>
                        <afes/PPolynomial.h>
                        <afes/FEMTree.h>
                        <afes/RegularGrid.h>
                        <afes/PreProcessor.h>
                        <apps_utils/CmdLineParser.h>
                        <apps_utils/io/Image.h>
                        <apps_utils/io/Ply.h>
                        <apps_utils/io/VertexFactory.h>
                        <apps_utils/io/VertexStreamImpl.h>)

target_precompile_headers (ChunkPLY REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (EDTInHeat REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (ImageStitching REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (PointInterpolant REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (PoissonRecon REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (SSDRecon REUSE_FROM AdaptiveTreeVisualization)
target_precompile_headers (SurfaceTrimmer REUSE_FROM AdaptiveTreeVisualization)

endif()


