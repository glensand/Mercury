cmake_minimum_required(VERSION 3.11)

project(MercuryMain)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

configure_file(mercuryconfig.h.in mercuryconfig.h)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(mercury)
add_subdirectory(map_generator)