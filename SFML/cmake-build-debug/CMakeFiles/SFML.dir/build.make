# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_SOURCE_DIR = /Users/LiamWood/CLionProjects/SFML

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/LiamWood/CLionProjects/SFML/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/SFML.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SFML.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SFML.dir/flags.make

CMakeFiles/SFML.dir/main.cpp.o: CMakeFiles/SFML.dir/flags.make
CMakeFiles/SFML.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/LiamWood/CLionProjects/SFML/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SFML.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SFML.dir/main.cpp.o -c /Users/LiamWood/CLionProjects/SFML/main.cpp

CMakeFiles/SFML.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SFML.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/LiamWood/CLionProjects/SFML/main.cpp > CMakeFiles/SFML.dir/main.cpp.i

CMakeFiles/SFML.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SFML.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/LiamWood/CLionProjects/SFML/main.cpp -o CMakeFiles/SFML.dir/main.cpp.s

CMakeFiles/SFML.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/SFML.dir/main.cpp.o.requires

CMakeFiles/SFML.dir/main.cpp.o.provides: CMakeFiles/SFML.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/SFML.dir/build.make CMakeFiles/SFML.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/SFML.dir/main.cpp.o.provides

CMakeFiles/SFML.dir/main.cpp.o.provides.build: CMakeFiles/SFML.dir/main.cpp.o


# Object files for target SFML
SFML_OBJECTS = \
"CMakeFiles/SFML.dir/main.cpp.o"

# External object files for target SFML
SFML_EXTERNAL_OBJECTS =

SFML: CMakeFiles/SFML.dir/main.cpp.o
SFML: CMakeFiles/SFML.dir/build.make
SFML: CMakeFiles/SFML.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/LiamWood/CLionProjects/SFML/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SFML"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SFML.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SFML.dir/build: SFML

.PHONY : CMakeFiles/SFML.dir/build

CMakeFiles/SFML.dir/requires: CMakeFiles/SFML.dir/main.cpp.o.requires

.PHONY : CMakeFiles/SFML.dir/requires

CMakeFiles/SFML.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SFML.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SFML.dir/clean

CMakeFiles/SFML.dir/depend:
	cd /Users/LiamWood/CLionProjects/SFML/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/LiamWood/CLionProjects/SFML /Users/LiamWood/CLionProjects/SFML /Users/LiamWood/CLionProjects/SFML/cmake-build-debug /Users/LiamWood/CLionProjects/SFML/cmake-build-debug /Users/LiamWood/CLionProjects/SFML/cmake-build-debug/CMakeFiles/SFML.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SFML.dir/depend

