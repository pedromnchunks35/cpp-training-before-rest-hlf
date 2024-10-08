# PUT MINIMUM VERSION OF CMAKE
cmake_minimum_required(VERSION 3.10)
# VERSION OF CPP 
set(CMAKE_CXX_STANDARD 14)
# THE NAME OF THE PROJECT
project(ExampleGtest LANGUAGES CXX)
# INCLUDE SOME DEPENDENCIES
include_directories(googletest/googletest/include)
# TO CREATE A EXECUTABLE FROM A GIVEN FILE
add_executable(${PROJECT_NAME} example.cpp)
# ADD SOME LIBRARIES
target_link_libraries(
${PROJECT_NAME} 
${CMAKE_SOURCE_DIR}/googletest/build/lib/libgtest.a
${CMAKE_SOURCE_DIR}/googletest/build/lib/libgtest_main.a
)
# USE THIS FLAG WHEN THREADS ARE ENABLED
set(CMAKE_THREAD_LIBS_INIT "-lpthread")
# USED TO ENABLE MULTI-THREADING SUPPORT AND LINK FOR THE PTHREAD LIBRARY
# ENSURES THAT WE USE PTHREAD LIBRARY FOR THREADING SUPPORT
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")
# INDICATING THREADS SUPPORT ENABLED
set(CMAKE_HAVE_THREADS_LIBRARY 1)
# SAYS TO WIN32 DONT USE WIN32 THREADS
set(CMAKE_USE_WIN32_THREADS_INIT 0)
# SAYS TO CMAKE USE PTHREADS
set(CMAKE_USE_PTHREADS_INIT 1)
# PREFER PTHREAD THREADS
set(THREADS_PREFER_PTHREAD_FLAG ON)
# DISCOVER THE TESTS BYHIMSELF
include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME})