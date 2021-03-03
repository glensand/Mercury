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

include(${CMAKE_ROOT}/vendor/rapidjson.cmake)

add_executable(mercury ${MERCURY_HEADERS} ${MERCURY_SOURSES})

target_include_directories (mercury 
    PUBLIC ${RAPIDJSON_INCLUDE_DIR}
)

add_dependencies(samelib rapidjson)