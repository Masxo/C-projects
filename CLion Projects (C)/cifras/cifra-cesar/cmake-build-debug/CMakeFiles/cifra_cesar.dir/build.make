# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.16

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.1.2\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\maxse\CLionProjects\cifra-cesar

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\maxse\CLionProjects\cifra-cesar\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/cifra_cesar.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cifra_cesar.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cifra_cesar.dir/flags.make

CMakeFiles/cifra_cesar.dir/main.c.obj: CMakeFiles/cifra_cesar.dir/flags.make
CMakeFiles/cifra_cesar.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\maxse\CLionProjects\cifra-cesar\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cifra_cesar.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\cifra_cesar.dir\main.c.obj   -c C:\Users\maxse\CLionProjects\cifra-cesar\main.c

CMakeFiles/cifra_cesar.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cifra_cesar.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\maxse\CLionProjects\cifra-cesar\main.c > CMakeFiles\cifra_cesar.dir\main.c.i

CMakeFiles/cifra_cesar.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cifra_cesar.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\maxse\CLionProjects\cifra-cesar\main.c -o CMakeFiles\cifra_cesar.dir\main.c.s

# Object files for target cifra_cesar
cifra_cesar_OBJECTS = \
"CMakeFiles/cifra_cesar.dir/main.c.obj"

# External object files for target cifra_cesar
cifra_cesar_EXTERNAL_OBJECTS =

cifra_cesar.exe: CMakeFiles/cifra_cesar.dir/main.c.obj
cifra_cesar.exe: CMakeFiles/cifra_cesar.dir/build.make
cifra_cesar.exe: CMakeFiles/cifra_cesar.dir/linklibs.rsp
cifra_cesar.exe: CMakeFiles/cifra_cesar.dir/objects1.rsp
cifra_cesar.exe: CMakeFiles/cifra_cesar.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\maxse\CLionProjects\cifra-cesar\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable cifra_cesar.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\cifra_cesar.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cifra_cesar.dir/build: cifra_cesar.exe

.PHONY : CMakeFiles/cifra_cesar.dir/build

CMakeFiles/cifra_cesar.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\cifra_cesar.dir\cmake_clean.cmake
.PHONY : CMakeFiles/cifra_cesar.dir/clean

CMakeFiles/cifra_cesar.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\maxse\CLionProjects\cifra-cesar C:\Users\maxse\CLionProjects\cifra-cesar C:\Users\maxse\CLionProjects\cifra-cesar\cmake-build-debug C:\Users\maxse\CLionProjects\cifra-cesar\cmake-build-debug C:\Users\maxse\CLionProjects\cifra-cesar\cmake-build-debug\CMakeFiles\cifra_cesar.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cifra_cesar.dir/depend

