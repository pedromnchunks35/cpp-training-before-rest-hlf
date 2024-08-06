# PUT MINIMUM VERSION OF CMAKE TO USE FETCH CONTENT WE NEED A MINIMUM OF 3.11
cmake_minimum_required(VERSION 3.11)
# VERSION OF CPP 
set(CMAKE_CXX_STANDARD 14)
# THE NAME OF THE PROJECT
project(ExampleGtest LANGUAGES CXX)
## ADD OUR OWN FILE CONTENT
include_directories(include)
# GITHUB FETCH OF DEPENDENCIES
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY git@github.com:google/googletest.git
    GIT_TAG b514bdc898e2951020cbdca1304b75f5950d1f59
)
FetchContent_MakeAvailable(googletest)
add_executable(${PROJECT_NAME} ./test/example.cpp)
add_executable(mockingproject ./test/testDummy.cpp ./src/dummy.cpp)
target_link_libraries(${PROJECT_NAME} gtest_main gmock_main)
target_link_libraries(mockingproject gtest_main gmock_main)
# DISCOVER THE TESTS BYHIMSELF
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})