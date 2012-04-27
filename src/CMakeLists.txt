# Create a library called Library.lib

include_directories (${base_SOURCE_DIR}/src)
include_directories (${base_SOURCE_DIR}/src/data_structures) 
include_directories (${base_SOURCE_DIR}/src/inline) 

add_library(library library.cpp)
