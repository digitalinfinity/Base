# The name of our project is "BASE". CMakeLists files in this project can 
# refer to the root source directory of the project as ${base_SOURCE_DIR} and 
# to the root binary directory of the project as ${base_BINARY_DIR}. 
cmake_minimum_required (VERSION 2.8) 
project (base)

add_subdirectory (src) 
add_subdirectory (test)