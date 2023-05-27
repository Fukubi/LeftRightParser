cmake_minimum_required(VERSION 3.26.4)

project(lrkparser VERSION 0.1.0)

include(CTest)

add_subdirectory(src)
add_subdirectory(external)
add_subdirectory(tests)