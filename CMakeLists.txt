cmake_minimum_required(VERSION 3.30)

project(dstl VERSION 0.0.1 LANGUAGES CXX) 

execute_process(COMMAND git submodule update --init --recursive -- lib/gtest WORKING_DIRECTORY ${PROJECT_SOURCE_DIR})

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/lib")
add_executable(main src/main.cpp)