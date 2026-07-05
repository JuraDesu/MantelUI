cmake_minimum_required(VERSION 3.20)

project(MantelUITest)

file(GLOB_RECURSE SOURCES src/*.cpp)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/)

find_package(raylib REQUIRED)

add_executable(MantelUITest ${SOURCES})

target_link_libraries(MantelUITest raylib)
