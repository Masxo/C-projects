# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\Users\maxse\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7319.72\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\maxse\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\202.7319.72\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "C:\Users\maxse\Projects\CLion Projects (C)\substituir-string"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "C:\Users\maxse\Projects\CLion Projects (C)\substituir-string\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/substituir_string.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/substituir_string.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/substituir_string.dir/flags.make

CMakeFiles/substituir_string.dir/main.c.obj: CMakeFiles/substituir_string.dir/flags.make
CMakeFiles/substituir_string.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="C:\Users\maxse\Projects\CLion Projects (C)\substituir-string\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/substituir_string.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\substituir_string.dir\main.c.obj   -c "C:\Users\maxse\Projects\CLion Projects (C)\substituir-string\main.c"

CMakeFiles/substituir_string.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/substituir_string.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "C:\Users\maxse\Projects\CLion Projects (C)\substituir-string\main.c" > CMakeFiles\substituir_string.dir\main.c.i

CMakeFiles/substituir_string.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/substituir_string.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "C:\Users\maxse\Projects\CLion Projects (C)\substituir-string\main.c" -o CMakeFiles\substituir_string.dir\main.c.s

# Object files for target substituir_string
substituir_string_OBJECTS = \
"CMakeFiles/substituir_string.dir/main.c.obj"

# External object files for target substituir_string
substituir_string_EXTERNAL_OBJECTS =

substituir_string.exe: CMakeFiles/substituir_string.dir/main.c.obj
substituir_string.exe: CMakeFiles/substituir_string.dir/build.make
substituir_string.exe: CMakeFiles/substituir_string.dir/linklibs.rsp
substituir_string.exe: CMakeFiles/substituir_string.dir/objects1.rsp
substituir_string.exe: CMakeFiles/substituir_string.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="C:\Users\maxse\Projects\CLion Projects (C)\substituir-string\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable substituir_string.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\substituir_string.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/substituir_string.dir/build: substituir_string.exe

.PHONY : CMakeFiles/substituir_string.dir/build

CMakeFiles/substituir_string.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\substituir_string.dir\cmake_clean.cmake
.PHONY : CMakeFiles/substituir_string.dir/clean

CMakeFiles/substituir_string.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "C:\Users\maxse\Projects\CLion Projects (C)\substituir-string" "C:\Users\maxse\Projects\CLion Projects (C)\substituir-string" "C:\Users\maxse\Projects\CLion Projects (C)\substituir-string\cmake-build-debug" "C:\Users\maxse\Projects\CLion Projects (C)\substituir-string\cmake-build-debug" "C:\Users\maxse\Projects\CLion Projects (C)\substituir-string\cmake-build-debug\CMakeFiles\substituir_string.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/substituir_string.dir/depend

