cmake_minimum_required(VERSION 3.12)

project(nei CXX)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCES "source/nei/*.cpp" "include/nei/*.hpp" "include/nei/*.tpp")

add_executable(nei ${SOURCES})
target_include_directories(nei PUBLIC "include")