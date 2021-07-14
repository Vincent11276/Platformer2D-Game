FetchContent_GetProperties(box2d)

if(NOT box2d_POPULATED)
	message(STATUS "Fetching Box2D v${BOX2D_VERSION}")
	
	FetchContent_Populate(box2d)

	set(BOX2D_BUILD_EXAMPLES CACHE BOOL OFF)	
	
	add_subdirectory(${box2d_SOURCE_DIR} ${box2d_BINARY_DIR})
endif()

