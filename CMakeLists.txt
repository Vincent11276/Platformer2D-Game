cmake_minimum_required(VERSION 3.18.4)

project(SpaceShooter)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS code/*.cpp)

add_executable("${PROJECT_NAME}" ${SOURCES})

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
add_compile_options(-Wall -Wextra -pedantic -Og)

include(FetchContent)

FetchContent_Declare(
	sfml
	URL https://github.com/SFML/SFML/archive/refs/tags/2.5.1.zip
	)
FetchContent_MakeAvailable(sfml)

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
	)
