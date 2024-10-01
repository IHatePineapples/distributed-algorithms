cmake_minimum_required(VERSION 3.16)

project("Distributed Algorithms"
    VERSION 1.0.0
    LANGUAGES CXX
)   

include_directories(${CMAKE_SOURCE_DIR})

add_subdirectory(node)
add_subdirectory(tree_wave)
