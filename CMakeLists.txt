cmake_minimum_required(VERSION 3.29)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_COMPILER gcc)
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_MAKE_PROGRAM make)

project(rayengine VERSION 0.2.0)

add_compile_options(-Wall -O2)

include_directories("C:/raylib/raylib/src")
include_directories("C:/raylib/raylib/src/external")

file(GLOB_RECURSE SRC_FILE CONFIGURE_DEPENDS ${CMAKE_SOURCE_DIR}/src/*.cpp ${CMAKE_SOURCE_DIR}/src/*.h)

add_library(rayengine STATIC ${SRC_FILE})
