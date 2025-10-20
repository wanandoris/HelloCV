cmake_minimum_required(VERSION 3.15)

project(week2)
file(GLOB SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/src)
set(EXECUTABLE_OUTPUT_PATH /home/wanan/VScode/week2)
add_executable(Cipher ${SOURCES} ${CMAKE_CURRENT_SOURCE_DIR}/src/head.hpp)