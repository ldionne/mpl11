# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/2.8.11.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/2.8.11.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/local/Cellar/cmake/2.8.11.2/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ldionne/code/mpl11

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ldionne/code/mpl11/build

# Include any dependencies generated for this target.
include test/CMakeFiles/functional_bind.dir/depend.make

# Include the progress variables for this target.
include test/CMakeFiles/functional_bind.dir/progress.make

# Include the compile flags for this target's objects.
include test/CMakeFiles/functional_bind.dir/flags.make

test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o: test/CMakeFiles/functional_bind.dir/flags.make
test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o: ../test/functional/bind.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/ldionne/code/mpl11/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o"
	cd /Users/ldionne/code/mpl11/build/test && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/functional_bind.dir/functional/bind.cpp.o -c /Users/ldionne/code/mpl11/test/functional/bind.cpp

test/CMakeFiles/functional_bind.dir/functional/bind.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/functional_bind.dir/functional/bind.cpp.i"
	cd /Users/ldionne/code/mpl11/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/ldionne/code/mpl11/test/functional/bind.cpp > CMakeFiles/functional_bind.dir/functional/bind.cpp.i

test/CMakeFiles/functional_bind.dir/functional/bind.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/functional_bind.dir/functional/bind.cpp.s"
	cd /Users/ldionne/code/mpl11/build/test && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/ldionne/code/mpl11/test/functional/bind.cpp -o CMakeFiles/functional_bind.dir/functional/bind.cpp.s

test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o.requires:
.PHONY : test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o.requires

test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o.provides: test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o.requires
	$(MAKE) -f test/CMakeFiles/functional_bind.dir/build.make test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o.provides.build
.PHONY : test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o.provides

test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o.provides.build: test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o

# Object files for target functional_bind
functional_bind_OBJECTS = \
"CMakeFiles/functional_bind.dir/functional/bind.cpp.o"

# External object files for target functional_bind
functional_bind_EXTERNAL_OBJECTS =

test/functional_bind: test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o
test/functional_bind: test/CMakeFiles/functional_bind.dir/build.make
test/functional_bind: test/CMakeFiles/functional_bind.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable functional_bind"
	cd /Users/ldionne/code/mpl11/build/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/functional_bind.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
test/CMakeFiles/functional_bind.dir/build: test/functional_bind
.PHONY : test/CMakeFiles/functional_bind.dir/build

test/CMakeFiles/functional_bind.dir/requires: test/CMakeFiles/functional_bind.dir/functional/bind.cpp.o.requires
.PHONY : test/CMakeFiles/functional_bind.dir/requires

test/CMakeFiles/functional_bind.dir/clean:
	cd /Users/ldionne/code/mpl11/build/test && $(CMAKE_COMMAND) -P CMakeFiles/functional_bind.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/functional_bind.dir/clean

test/CMakeFiles/functional_bind.dir/depend:
	cd /Users/ldionne/code/mpl11/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ldionne/code/mpl11 /Users/ldionne/code/mpl11/test /Users/ldionne/code/mpl11/build /Users/ldionne/code/mpl11/build/test /Users/ldionne/code/mpl11/build/test/CMakeFiles/functional_bind.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/functional_bind.dir/depend
