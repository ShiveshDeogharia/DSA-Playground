cmake_minimum_required(VERSION 3.10)
project(DSAPlayground)

set(CMAKE_CXX_STANDARD 20)

# ----------------------------
# 1. Include main headers
# ----------------------------
include_directories(include)

# ----------------------------
# 2. Build the main executable
# ----------------------------
add_executable(dsa_playground
    src/main.cpp
    src/array_ds.cpp
    src/linked_list_ds.cpp
    src/stack_ds.cpp
    src/queue_ds.cpp
    src/bst_ds.cpp
    src/graph_ds.cpp
)

# ----------------------------
# 3. Fetch GoogleTest
# ----------------------------
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

# ----------------------------
# 4. Add test executable
# ----------------------------
add_executable(tests
    tests/test_array_ds.cpp
    tests/test_linked_list_ds.cpp
    src/array_ds.cpp
    src/linked_list_ds.cpp
)

target_link_libraries(tests gtest_main)
target_include_directories(tests PRIVATE ${gtest_SOURCE_DIR}/include)

# REQUIRED for `ctest` to discover tests
include(GoogleTest)
gtest_discover_tests(tests)
