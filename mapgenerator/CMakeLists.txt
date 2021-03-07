cmake_minimum_required(VERSION 3.11)

project(map_generator)

file(GLOB MAP_GENERATOR_HEADERS
    *.h)
	
file(GLOB MAP_GENERATOR_SOURSES
    *.cpp)

add_executable(map_generator ${MAP_GENERATOR_HEADERS} ${MAP_GENERATOR_SOURSES})