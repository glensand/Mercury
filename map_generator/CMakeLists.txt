cmake_minimum_required(VERSION 3.11)

project(map_generator)

file(GLOB MAP_GENERATOR_HEADERS
    *.h)
	
file(GLOB MAP_GENERATOR_SOURSES
    *.cpp)

add_executable(map_generator ${SAMPLE_HEADERS} ${SAMPLE_SOURSES})
target_include_directories(sample PUBLIC ../samelib)
target_link_libraries(sample samelib)