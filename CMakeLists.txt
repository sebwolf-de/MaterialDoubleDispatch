cmake_minimum_required(VERSION 3.10)

# set the project name
project(FluxFactory)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#gcov
set(CMAKE_CXX_FLAGS "-g -O0 -Wall -fprofile-arcs -ftest-coverage")

#build and link libraries and executable
add_library(FluxFactory src/FluxFactory.cpp)
add_library(Material src/Material.cpp)

add_executable(main src/main.cpp)
target_link_libraries(main PUBLIC FluxFactory Material)

#testing
find_package(CxxTest)
if(CXXTEST_FOUND)
  include_directories(${CXXTEST_INCLUDE_DIR})
  enable_testing()

  CXXTEST_ADD_TEST(test_computeFlux test_computeFlux.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/tests/test_computeFlux.t.h)
  target_link_libraries(test_computeFlux PUBLIC FluxFactory Material) # as needed
endif()


