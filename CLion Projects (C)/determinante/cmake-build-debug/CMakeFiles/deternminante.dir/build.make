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
CMAKE_SOURCE_DIR = C:\Users\maxse\CLionProjects\determinante

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\maxse\CLionProjects\determinante\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/deternminante.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/deternminante.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/deternminante.dir/flags.make

CMakeFiles/deternminante.dir/main.c.obj: CMakeFiles/deternminante.dir/flags.make
CMakeFiles/deternminante.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\maxse\CLionProjects\determinante\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/deternminante.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\deternminante.dir\main.c.obj   -c C:\Users\maxse\CLionProjects\determinante\main.c

CMakeFiles/deternminante.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/deternminante.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\maxse\CLionProjects\determinante\main.c > CMakeFiles\deternminante.dir\main.c.i

CMakeFiles/deternminante.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/deternminante.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\maxse\CLionProjects\determinante\main.c -o CMakeFiles\deternminante.dir\main.c.s

# Object files for target deternminante
deternminante_OBJECTS = \
"CMakeFiles/deternminante.dir/main.c.obj"

# External object files for target deternminante
deternminante_EXTERNAL_OBJECTS =

deternminante.exe: CMakeFiles/deternminante.dir/main.c.obj
deternminante.exe: CMakeFiles/deternminante.dir/build.make
deternminante.exe: CMakeFiles/deternminante.dir/linklibs.rsp
deternminante.exe: CMakeFiles/deternminante.dir/objects1.rsp
deternminante.exe: CMakeFiles/deternminante.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\maxse\CLionProjects\determinante\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable deternminante.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\deternminante.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/deternminante.dir/build: deternminante.exe

.PHONY : CMakeFiles/deternminante.dir/build

CMakeFiles/deternminante.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\deternminante.dir\cmake_clean.cmake
.PHONY : CMakeFiles/deternminante.dir/clean

CMakeFiles/deternminante.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\maxse\CLionProjects\determinante C:\Users\maxse\CLionProjects\determinante C:\Users\maxse\CLionProjects\determinante\cmake-build-debug C:\Users\maxse\CLionProjects\determinante\cmake-build-debug C:\Users\maxse\CLionProjects\determinante\cmake-build-debug\CMakeFiles\deternminante.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/deternminante.dir/depend
