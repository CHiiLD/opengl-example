cmake_minimum_required(VERSION 3.8)
project(opengl)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -framework GLUT -framework OpenGL")

include_directories(/Users/Child/Github/googletest/include/gtest)
add_executable(OpenGLTests part2_intro.cpp part3_pipeline.cpp main.cpp)

target_link_libraries(OpenGLTests gtest gtest_main)