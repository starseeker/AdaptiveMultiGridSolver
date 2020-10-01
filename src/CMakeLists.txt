include_directories("${CMAKE_SOURCE_DIR}/include")

# AdaptiveTreeVisualization
add_executable(AdaptiveTreeVisualization AdaptiveTreeVisualization.cpp)
target_link_libraries(AdaptiveTreeVisualization
	PRIVATE
	${ZLIB_LIBRARIES}
	${PNG_LIBRARIES}
	${JPEG_LIBRARIES})

install(TARGETS AdaptiveTreeVisualization
	DESTINATION ${BIN_DIR})

# ChunkPLY 
add_executable(ChunkPLY ChunkPLY.cpp)
target_link_libraries(ChunkPLY
	PRIVATE
	${ZLIB_LIBRARIES}
	${PNG_LIBRARIES}
	${JPEG_LIBRARIES})

install(TARGETS ChunkPLY
	DESTINATION ${BIN_DIR})

# EDTInHeat 
add_executable(EDTInHeat EDTInHeat.cpp)
target_link_libraries(EDTInHeat
	PRIVATE
	${ZLIB_LIBRARIES}
	${PNG_LIBRARIES}
	${JPEG_LIBRARIES})

install(TARGETS EDTInHeat
	DESTINATION ${BIN_DIR})

# ImageStitching
add_executable(ImageStitching ImageStitching.cpp)
target_link_libraries(ImageStitching
	PRIVATE
	${ZLIB_LIBRARIES}
	${PNG_LIBRARIES}
	${JPEG_LIBRARIES})

install(TARGETS ImageStitching
	DESTINATION ${BIN_DIR})

# PointInterpolant
add_executable(PointInterpolant PointInterpolant.cpp)
target_link_libraries(PointInterpolant
	PRIVATE
	${ZLIB_LIBRARIES}
	${PNG_LIBRARIES}
	${JPEG_LIBRARIES})

install(TARGETS PointInterpolant
	DESTINATION ${BIN_DIR})

# PoissonRecon
add_executable(PoissonRecon PoissonRecon.cpp)
target_link_libraries(PoissonRecon
	PRIVATE
	${ZLIB_LIBRARIES}
	${PNG_LIBRARIES}
	${JPEG_LIBRARIES})

install(TARGETS PoissonRecon
	DESTINATION ${BIN_DIR})

# SSDRecon
add_executable(SSDRecon SSDRecon.cpp)
target_link_libraries(SSDRecon
	PRIVATE
	${ZLIB_LIBRARIES}
	${PNG_LIBRARIES}
	${JPEG_LIBRARIES})

install(TARGETS SSDRecon
	DESTINATION ${BIN_DIR})

# SurfaceTrimmer
add_executable(SurfaceTrimmer SurfaceTrimmer.cpp)
target_link_libraries(SurfaceTrimmer
	PRIVATE
	${ZLIB_LIBRARIES}
	${PNG_LIBRARIES}
	${JPEG_LIBRARIES})

install(TARGETS SurfaceTrimmer
	DESTINATION ${BIN_DIR})

