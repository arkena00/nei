cmake_minimum_required(VERSION 3.12)

project(nei CXX)

#-------------------------------------------------------
#                        VARS
#-------------------------------------------------------
# roots
set(NEI_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
set(NEI_BIN_ROOT ${NEI_ROOT}/bin)

set(CMAKE_CXX_STANDARD 17)

add_library(lib_nei INTERFACE)
target_include_directories(lib_nei INTERFACE "include" "third_party/spdlog/include")

file(GLOB_RECURSE SOURCES "source/nei/*.cpp" "include/nei/*.hpp" "include/nei/*.tpp")

add_executable(nei ${SOURCES})

target_link_libraries(nei lib_nei)



add_subdirectory(experimental)
