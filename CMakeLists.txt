cmake_minimum_required(VERSION 3.10)

# set the project name
project(main)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_library(FluxFactory src/FluxFactory.cpp)
add_library(Material src/Material.cpp)

add_executable(main src/main.cpp)

target_link_libraries(main PUBLIC FluxFactory Material)

