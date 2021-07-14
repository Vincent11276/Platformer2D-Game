cmake_minimum_required(VERSION 3.18.4)

project(Platformer2D)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS code/*.cpp)

add_executable("${PROJECT_NAME}" ${SOURCES})

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
	add_compile_options(-Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
	add_compile_options(-Wall -Wextra -pedantic)
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
	add_compile_options(/Wall)
endif()

include(FetchContent)

FetchContent_Declare(
	sfml
	URL https://github.com/SFML/SFML/archive/refs/tags/2.5.1.zip
)

FetchContent_Declare(
	box2d
	URL https://github.com/erincatto/box2d/archive/refs/tags/v2.4.1.zip
)

FetchContent_MakeAvailable(sfml)
FetchContent_MakeAvailable(box2d)

# Set to use C++17
set_target_properties(
	"${PROJECT_NAME}"
	PROPERTIES
	CXX_STANDARD 17
	)

target_include_directories(
	"${PROJECT_NAME}"
	PRIVATE
	header
	)

target_link_libraries(
	"${PROJECT_NAME}"
	PRIVATE
	sfml-graphics
	sfml-window
	sfml-system
	box2d::box2d
	)
