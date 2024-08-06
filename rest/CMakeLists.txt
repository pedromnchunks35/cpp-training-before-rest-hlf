# GENERAL SETUP
## MINIMUM VERSION
cmake_minimum_required(VERSION 3.10)
## NAME OF THE PROJECT
project(my_rest_api)
## VERSION OF CPP
set(CMAKE_CXX_STANDARD 14)
## INCLUDE HEADER FILES INSIDE OF INCLUDE
include_directories(include)

# TESTS SETUP
## GITHUB FETCH GOOGLE TEST DEPENDENCIE
include(FetchContent)
FetchContent_Declare(
    googletest
    GIT_REPOSITORY git@github.com:google/googletest.git
    GIT_TAG b514bdc898e2951020cbdca1304b75f5950d1f59
)
FetchContent_MakeAvailable(googletest)
## FILE DEPENDENCIES
set(
SOURCES_TEST
./test/test1.cpp
./test/test2.cpp
)



# BOOST LIBRARY SETUP
##  SPECIFY THE ROOT AND A LIBRARY FOR BOOST
set(BOOST_ROOT "/home/pedromn35/cpp-libraries/boost_1_85_0")
set(BOOST_LIBRARYDIR "/home/pedromn35/cpp-libraries/boost_1_85_0/stage/lib")

## FIND BOOST
find_package(Boost REQUIRED)
## INCLUDE BOOST HEADERS
include_directories(${Boost_INCLUDE_DIRS})
include_directories(/home/pedromn35/cpp-libraries/boost_1_85_0/boost)

set(
SOURCES
./src/main.cpp
)


# EXECUTABLES
## SRC
add_executable(my_rest_api ${SOURCES})
## TEST
add_executable(my_rest_api_test ${SOURCES_TEST})

# TARGETS
## TEST
###  LINKING LIBRARIES FOR THE TESTS
target_link_libraries(my_rest_api_test gtest_main gmock_main)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(GoogleTest)
gtest_discover_tests(my_rest_api_test)