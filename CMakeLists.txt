cmake_minimum_required(VERSION 3.18.4)

project(SpaceShooter)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS code/*.cpp)

add_executable("${PROJECT_NAME}" ${SOURCES})

set(CMAKE_EXPORT_COMPILE_COMMANDS 1)
add_compile_options(-Wall -Wextra -pedantic -Werror -Og)

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
	)
