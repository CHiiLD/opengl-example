# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/Child/ClionProjects/opengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/Child/ClionProjects/opengl/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OpenGLTests.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/OpenGLTests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OpenGLTests.dir/flags.make

CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o: CMakeFiles/OpenGLTests.dir/flags.make
CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o: ../part2_intro.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Child/ClionProjects/opengl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o -c /Users/Child/ClionProjects/opengl/part2_intro.cpp

CMakeFiles/OpenGLTests.dir/part2_intro.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLTests.dir/part2_intro.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Child/ClionProjects/opengl/part2_intro.cpp > CMakeFiles/OpenGLTests.dir/part2_intro.cpp.i

CMakeFiles/OpenGLTests.dir/part2_intro.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLTests.dir/part2_intro.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Child/ClionProjects/opengl/part2_intro.cpp -o CMakeFiles/OpenGLTests.dir/part2_intro.cpp.s

CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o.requires:

.PHONY : CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o.requires

CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o.provides: CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o.requires
	$(MAKE) -f CMakeFiles/OpenGLTests.dir/build.make CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o.provides.build
.PHONY : CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o.provides

CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o.provides.build: CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o


CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o: CMakeFiles/OpenGLTests.dir/flags.make
CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o: ../part3_pipeline.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Child/ClionProjects/opengl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o -c /Users/Child/ClionProjects/opengl/part3_pipeline.cpp

CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Child/ClionProjects/opengl/part3_pipeline.cpp > CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.i

CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Child/ClionProjects/opengl/part3_pipeline.cpp -o CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.s

CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o.requires:

.PHONY : CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o.requires

CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o.provides: CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o.requires
	$(MAKE) -f CMakeFiles/OpenGLTests.dir/build.make CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o.provides.build
.PHONY : CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o.provides

CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o.provides.build: CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o


CMakeFiles/OpenGLTests.dir/main.cpp.o: CMakeFiles/OpenGLTests.dir/flags.make
CMakeFiles/OpenGLTests.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/Child/ClionProjects/opengl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OpenGLTests.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OpenGLTests.dir/main.cpp.o -c /Users/Child/ClionProjects/opengl/main.cpp

CMakeFiles/OpenGLTests.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OpenGLTests.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/Child/ClionProjects/opengl/main.cpp > CMakeFiles/OpenGLTests.dir/main.cpp.i

CMakeFiles/OpenGLTests.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OpenGLTests.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/Child/ClionProjects/opengl/main.cpp -o CMakeFiles/OpenGLTests.dir/main.cpp.s

CMakeFiles/OpenGLTests.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/OpenGLTests.dir/main.cpp.o.requires

CMakeFiles/OpenGLTests.dir/main.cpp.o.provides: CMakeFiles/OpenGLTests.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/OpenGLTests.dir/build.make CMakeFiles/OpenGLTests.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/OpenGLTests.dir/main.cpp.o.provides

CMakeFiles/OpenGLTests.dir/main.cpp.o.provides.build: CMakeFiles/OpenGLTests.dir/main.cpp.o


# Object files for target OpenGLTests
OpenGLTests_OBJECTS = \
"CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o" \
"CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o" \
"CMakeFiles/OpenGLTests.dir/main.cpp.o"

# External object files for target OpenGLTests
OpenGLTests_EXTERNAL_OBJECTS =

OpenGLTests: CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o
OpenGLTests: CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o
OpenGLTests: CMakeFiles/OpenGLTests.dir/main.cpp.o
OpenGLTests: CMakeFiles/OpenGLTests.dir/build.make
OpenGLTests: CMakeFiles/OpenGLTests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/Child/ClionProjects/opengl/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable OpenGLTests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OpenGLTests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OpenGLTests.dir/build: OpenGLTests

.PHONY : CMakeFiles/OpenGLTests.dir/build

CMakeFiles/OpenGLTests.dir/requires: CMakeFiles/OpenGLTests.dir/part2_intro.cpp.o.requires
CMakeFiles/OpenGLTests.dir/requires: CMakeFiles/OpenGLTests.dir/part3_pipeline.cpp.o.requires
CMakeFiles/OpenGLTests.dir/requires: CMakeFiles/OpenGLTests.dir/main.cpp.o.requires

.PHONY : CMakeFiles/OpenGLTests.dir/requires

CMakeFiles/OpenGLTests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OpenGLTests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OpenGLTests.dir/clean

CMakeFiles/OpenGLTests.dir/depend:
	cd /Users/Child/ClionProjects/opengl/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/Child/ClionProjects/opengl /Users/Child/ClionProjects/opengl /Users/Child/ClionProjects/opengl/cmake-build-debug /Users/Child/ClionProjects/opengl/cmake-build-debug /Users/Child/ClionProjects/opengl/cmake-build-debug/CMakeFiles/OpenGLTests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OpenGLTests.dir/depend
