# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/build

# Include any dependencies generated for this target.
include CMakeFiles/my_rest_api_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/my_rest_api_test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/my_rest_api_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/my_rest_api_test.dir/flags.make

CMakeFiles/my_rest_api_test.dir/test/test1.cpp.o: CMakeFiles/my_rest_api_test.dir/flags.make
CMakeFiles/my_rest_api_test.dir/test/test1.cpp.o: /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/test/test1.cpp
CMakeFiles/my_rest_api_test.dir/test/test1.cpp.o: CMakeFiles/my_rest_api_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/my_rest_api_test.dir/test/test1.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_rest_api_test.dir/test/test1.cpp.o -MF CMakeFiles/my_rest_api_test.dir/test/test1.cpp.o.d -o CMakeFiles/my_rest_api_test.dir/test/test1.cpp.o -c /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/test/test1.cpp

CMakeFiles/my_rest_api_test.dir/test/test1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/my_rest_api_test.dir/test/test1.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/test/test1.cpp > CMakeFiles/my_rest_api_test.dir/test/test1.cpp.i

CMakeFiles/my_rest_api_test.dir/test/test1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/my_rest_api_test.dir/test/test1.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/test/test1.cpp -o CMakeFiles/my_rest_api_test.dir/test/test1.cpp.s

CMakeFiles/my_rest_api_test.dir/test/test2.cpp.o: CMakeFiles/my_rest_api_test.dir/flags.make
CMakeFiles/my_rest_api_test.dir/test/test2.cpp.o: /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/test/test2.cpp
CMakeFiles/my_rest_api_test.dir/test/test2.cpp.o: CMakeFiles/my_rest_api_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/my_rest_api_test.dir/test/test2.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/my_rest_api_test.dir/test/test2.cpp.o -MF CMakeFiles/my_rest_api_test.dir/test/test2.cpp.o.d -o CMakeFiles/my_rest_api_test.dir/test/test2.cpp.o -c /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/test/test2.cpp

CMakeFiles/my_rest_api_test.dir/test/test2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/my_rest_api_test.dir/test/test2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/test/test2.cpp > CMakeFiles/my_rest_api_test.dir/test/test2.cpp.i

CMakeFiles/my_rest_api_test.dir/test/test2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/my_rest_api_test.dir/test/test2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/test/test2.cpp -o CMakeFiles/my_rest_api_test.dir/test/test2.cpp.s

# Object files for target my_rest_api_test
my_rest_api_test_OBJECTS = \
"CMakeFiles/my_rest_api_test.dir/test/test1.cpp.o" \
"CMakeFiles/my_rest_api_test.dir/test/test2.cpp.o"

# External object files for target my_rest_api_test
my_rest_api_test_EXTERNAL_OBJECTS =

my_rest_api_test: CMakeFiles/my_rest_api_test.dir/test/test1.cpp.o
my_rest_api_test: CMakeFiles/my_rest_api_test.dir/test/test2.cpp.o
my_rest_api_test: CMakeFiles/my_rest_api_test.dir/build.make
my_rest_api_test: lib/libgtest_main.a
my_rest_api_test: lib/libgmock_main.a
my_rest_api_test: lib/libgmock.a
my_rest_api_test: lib/libgtest.a
my_rest_api_test: CMakeFiles/my_rest_api_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable my_rest_api_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/my_rest_api_test.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=my_rest_api_test -D TEST_EXECUTABLE=/run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/build/my_rest_api_test -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=my_rest_api_test_TESTS -D CTEST_FILE=/run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/build/my_rest_api_test[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/my_rest_api_test.dir/build: my_rest_api_test
.PHONY : CMakeFiles/my_rest_api_test.dir/build

CMakeFiles/my_rest_api_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/my_rest_api_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/my_rest_api_test.dir/clean

CMakeFiles/my_rest_api_test.dir/depend:
	cd /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/build /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/build /run/media/pedromn35/disk2-home/projects/cpp-training-before-rest-hlf/rest/build/CMakeFiles/my_rest_api_test.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/my_rest_api_test.dir/depend

