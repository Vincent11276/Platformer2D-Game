# Taken from https://github.com/eliasdaler/imgui-sfml-fetchcontent/blob/master/dependencies/CMakeLists.txt with slight modification

include(FetchContent)

option(USE_SYSTEM_DEPS CACHE OFF)
option(LINK_DEPS_STATIC CACHE OFF)

# Don't build shared libs if we want to link to deps statically
if(LINK_DEPS_STATIC)
	set(BUILD_SHARED_LIBS OFF)
else()
	set(BUILD_SHARED_LIBS ON)
endif()

message(STATUS "Fetching third party libraries")
#======================================

set(SFML_VERSION 2.5.1)
set(IMGUI_VERSION 1.82)
set(IMGUI_SFML_VERSION 2.3)
set(BOX2D_VERSION 2.4.1)

FetchContent_Declare(
	SFML
	URL "https://github.com/SFML/SFML/archive/${SFML_VERSION}.zip"
	)

FetchContent_Declare(
	imgui
	URL "https://github.com/ocornut/imgui/archive/v${IMGUI_VERSION}.zip"
	)

FetchContent_Declare(
	imgui-sfml
	URL "https://github.com/eliasdaler/imgui-sfml/archive/refs/tags/v${IMGUI_SFML_VERSION}.zip"
	)

FetchContent_Declare(
	box2d
	URL "https://github.com/erincatto/box2d/archive/refs/tags/v${BOX2D_VERSION}.zip"
	)

add_subdirectory(sfml)
add_subdirectory(imgui)
add_subdirectory(imgui-sfml)
add_subdirectory(box2d)

#======================================
message(STATUS "Fetching thirdparty libraries done")
