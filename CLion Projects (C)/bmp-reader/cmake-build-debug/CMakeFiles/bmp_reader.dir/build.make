# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/bmp_reader.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/bmp_reader.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/bmp_reader.dir/flags.make

CMakeFiles/bmp_reader.dir/main.c.o: CMakeFiles/bmp_reader.dir/flags.make
CMakeFiles/bmp_reader.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/bmp_reader.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/bmp_reader.dir/main.c.o   -c "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader/main.c"

CMakeFiles/bmp_reader.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/bmp_reader.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader/main.c" > CMakeFiles/bmp_reader.dir/main.c.i

CMakeFiles/bmp_reader.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/bmp_reader.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader/main.c" -o CMakeFiles/bmp_reader.dir/main.c.s

# Object files for target bmp_reader
bmp_reader_OBJECTS = \
"CMakeFiles/bmp_reader.dir/main.c.o"

# External object files for target bmp_reader
bmp_reader_EXTERNAL_OBJECTS =

bmp_reader: CMakeFiles/bmp_reader.dir/main.c.o
bmp_reader: CMakeFiles/bmp_reader.dir/build.make
bmp_reader: CMakeFiles/bmp_reader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable bmp_reader"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/bmp_reader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/bmp_reader.dir/build: bmp_reader

.PHONY : CMakeFiles/bmp_reader.dir/build

CMakeFiles/bmp_reader.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/bmp_reader.dir/cmake_clean.cmake
.PHONY : CMakeFiles/bmp_reader.dir/clean

CMakeFiles/bmp_reader.dir/depend:
	cd "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader" "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader" "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader/cmake-build-debug" "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader/cmake-build-debug" "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/bmp-reader/cmake-build-debug/CMakeFiles/bmp_reader.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/bmp_reader.dir/depend

