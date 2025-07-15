cmake_minimum_required(VERSION 3.10)
project(DSAPlayground)

set(CMAKE_CXX_STANDARD 20)

# Add include directory for headers
include_directories(include)

# List all source files here
add_executable(dsa_playground
    src/main.cpp
    src/array_ds.cpp
    src/linked_list_ds.cpp
    src/stack_ds.cpp
    src/queue_ds.cpp
    src/bst_ds.cpp
    src/graph_ds.cpp
)
