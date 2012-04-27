# Make sure the compiler can find include files from our base library. 
include_directories (${base_SOURCE_DIR}/src) 
include_directories (${base_SOURCE_DIR}/src/data_structures) 
include_directories (${base_SOURCE_DIR}/extern/inc/) 
include_directories (${base_SOURCE_DIR}/test) 

# Make sure the linker can find the testbase library once it is built. 
link_directories (${base_BINARY_DIR}/src) 
link_directories (${base_SOURCE_DIR}/extern/lib/osx) 

# Add executable called "testbase" that is built from the source files 
# "Test.cpp" and "stdafx.cxx". The extensions are automatically found. 
add_executable (runtests Test.cpp stdafx.cpp data_structures/linked_list.cpp) 

# Link the executable to the base library. 
target_link_libraries (runtests library libgtest.a)