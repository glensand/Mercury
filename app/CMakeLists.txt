cmake_minimum_required(VERSION 3.11)

project(mercury)

file(GLOB MERCURY_HEADERS
    app/*.h
	command/*.h
	graphics/*.h
	input/*.h
	mode/*.h
	player/*.h
	world/*.h
	*.h
	)
	
file(GLOB MERCURY_SOURSES
    app/*.cpp
	command/*.cpp
	graphics/*.cpp
	input/*.cpp
	mode/*.cpp
	player/*.cpp
	world/*.cpp
	*.cpp
	)

add_executable(mercury ${MERCURY_HEADERS} ${MERCURY_SOURSES})


include(${CMAKE_ROOT}/Modules/ExternalProject.cmake)
include("../vendor/rapidjson.cmake")
find_package(SFML REQUIRED)

target_include_directories (mercury 
    PUBLIC ${RAPIDJSON_INCLUDE_DIR}
	PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries (mercury sfml-graphics sfml-window sfml-system)

add_dependencies(mercury rapidjson)