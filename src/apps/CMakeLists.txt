# AdaptiveTreeVisualization 
add_executable(AdaptiveTreeVisualization AdaptiveTreeVisualization.cpp)
target_link_libraries(AdaptiveTreeVisualization 
                       PRIVATE
                        amgs::amgs
                        apps_utils::apps_utils)
        
install(TARGETS AdaptiveTreeVisualization
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# ChunkPLY 
add_executable(ChunkPLY ChunkPLY.cpp)
target_link_libraries(ChunkPLY
                       PRIVATE
                        amgs::amgs
                        apps_utils::apps_utils)
        
install(TARGETS ChunkPLY
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# EDTInHeat 
add_executable(EDTInHeat EDTInHeat.cpp)
target_link_libraries(EDTInHeat
                      PRIVATE
                       amgs::amgs
                       apps_utils::apps_utils)
        
install(TARGETS EDTInHeat
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# ImageStitching 
add_executable(ImageStitching ImageStitching.cpp)
target_link_libraries(ImageStitching
                      PRIVATE
                       amgs::amgs
                       apps_utils::apps_utils)
        
install(TARGETS ImageStitching
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# PointInterpolant 
add_executable(PointInterpolant PointInterpolant.cpp)
target_link_libraries(PointInterpolant
                      PRIVATE
                       amgs::amgs
                       apps_utils::apps_utils)
        
install(TARGETS PointInterpolant
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# PoissonRecon 
add_executable(PoissonRecon PoissonRecon.cpp)
target_link_libraries(PoissonRecon
                      PRIVATE
                       amgs::amgs
                       apps_utils::apps_utils)

install(TARGETS PoissonRecon
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# SSDRecon 
add_executable(SSDRecon SSDRecon.cpp)
target_link_libraries(SSDRecon
                      PRIVATE
                       amgs::amgs
                       apps_utils::apps_utils)

install(TARGETS SSDRecon
        DESTINATION ${CMAKE_INSTALL_BINDIRs})

# SurfaceTrimmer 
add_executable(SurfaceTrimmer SurfaceTrimmer.cpp)
target_link_libraries(SurfaceTrimmer
                      PRIVATE
                       amgs::amgs
                       apps_utils::apps_utils)

install(TARGETS SurfaceTrimmer
        DESTINATION ${CMAKE_INSTALL_BINDIRs})



