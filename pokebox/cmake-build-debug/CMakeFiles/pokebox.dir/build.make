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
CMAKE_SOURCE_DIR = "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/pokebox.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pokebox.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pokebox.dir/flags.make

CMakeFiles/pokebox.dir/main.c.o: CMakeFiles/pokebox.dir/flags.make
CMakeFiles/pokebox.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/pokebox.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pokebox.dir/main.c.o   -c "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/main.c"

CMakeFiles/pokebox.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pokebox.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/main.c" > CMakeFiles/pokebox.dir/main.c.i

CMakeFiles/pokebox.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pokebox.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/main.c" -o CMakeFiles/pokebox.dir/main.c.s

CMakeFiles/pokebox.dir/SaveManager.c.o: CMakeFiles/pokebox.dir/flags.make
CMakeFiles/pokebox.dir/SaveManager.c.o: ../SaveManager.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/pokebox.dir/SaveManager.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pokebox.dir/SaveManager.c.o   -c "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/SaveManager.c"

CMakeFiles/pokebox.dir/SaveManager.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pokebox.dir/SaveManager.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/SaveManager.c" > CMakeFiles/pokebox.dir/SaveManager.c.i

CMakeFiles/pokebox.dir/SaveManager.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pokebox.dir/SaveManager.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/SaveManager.c" -o CMakeFiles/pokebox.dir/SaveManager.c.s

CMakeFiles/pokebox.dir/dataStructures.c.o: CMakeFiles/pokebox.dir/flags.make
CMakeFiles/pokebox.dir/dataStructures.c.o: ../dataStructures.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/pokebox.dir/dataStructures.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pokebox.dir/dataStructures.c.o   -c "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/dataStructures.c"

CMakeFiles/pokebox.dir/dataStructures.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pokebox.dir/dataStructures.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/dataStructures.c" > CMakeFiles/pokebox.dir/dataStructures.c.i

CMakeFiles/pokebox.dir/dataStructures.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pokebox.dir/dataStructures.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/dataStructures.c" -o CMakeFiles/pokebox.dir/dataStructures.c.s

CMakeFiles/pokebox.dir/PokeBox.c.o: CMakeFiles/pokebox.dir/flags.make
CMakeFiles/pokebox.dir/PokeBox.c.o: ../PokeBox.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/pokebox.dir/PokeBox.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pokebox.dir/PokeBox.c.o   -c "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/PokeBox.c"

CMakeFiles/pokebox.dir/PokeBox.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pokebox.dir/PokeBox.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/PokeBox.c" > CMakeFiles/pokebox.dir/PokeBox.c.i

CMakeFiles/pokebox.dir/PokeBox.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pokebox.dir/PokeBox.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/PokeBox.c" -o CMakeFiles/pokebox.dir/PokeBox.c.s

CMakeFiles/pokebox.dir/Pokemon.c.o: CMakeFiles/pokebox.dir/flags.make
CMakeFiles/pokebox.dir/Pokemon.c.o: ../Pokemon.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/pokebox.dir/Pokemon.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pokebox.dir/Pokemon.c.o   -c "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/Pokemon.c"

CMakeFiles/pokebox.dir/Pokemon.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pokebox.dir/Pokemon.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/Pokemon.c" > CMakeFiles/pokebox.dir/Pokemon.c.i

CMakeFiles/pokebox.dir/Pokemon.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pokebox.dir/Pokemon.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/Pokemon.c" -o CMakeFiles/pokebox.dir/Pokemon.c.s

CMakeFiles/pokebox.dir/PokeDex.c.o: CMakeFiles/pokebox.dir/flags.make
CMakeFiles/pokebox.dir/PokeDex.c.o: ../PokeDex.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/pokebox.dir/PokeDex.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pokebox.dir/PokeDex.c.o   -c "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/PokeDex.c"

CMakeFiles/pokebox.dir/PokeDex.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pokebox.dir/PokeDex.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/PokeDex.c" > CMakeFiles/pokebox.dir/PokeDex.c.i

CMakeFiles/pokebox.dir/PokeDex.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pokebox.dir/PokeDex.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/PokeDex.c" -o CMakeFiles/pokebox.dir/PokeDex.c.s

CMakeFiles/pokebox.dir/SpriteManager.c.o: CMakeFiles/pokebox.dir/flags.make
CMakeFiles/pokebox.dir/SpriteManager.c.o: ../SpriteManager.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/pokebox.dir/SpriteManager.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pokebox.dir/SpriteManager.c.o   -c "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/SpriteManager.c"

CMakeFiles/pokebox.dir/SpriteManager.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pokebox.dir/SpriteManager.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/SpriteManager.c" > CMakeFiles/pokebox.dir/SpriteManager.c.i

CMakeFiles/pokebox.dir/SpriteManager.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pokebox.dir/SpriteManager.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/SpriteManager.c" -o CMakeFiles/pokebox.dir/SpriteManager.c.s

CMakeFiles/pokebox.dir/Util.c.o: CMakeFiles/pokebox.dir/flags.make
CMakeFiles/pokebox.dir/Util.c.o: ../Util.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/pokebox.dir/Util.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pokebox.dir/Util.c.o   -c "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/Util.c"

CMakeFiles/pokebox.dir/Util.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pokebox.dir/Util.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/Util.c" > CMakeFiles/pokebox.dir/Util.c.i

CMakeFiles/pokebox.dir/Util.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pokebox.dir/Util.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/Util.c" -o CMakeFiles/pokebox.dir/Util.c.s

CMakeFiles/pokebox.dir/PokeType.c.o: CMakeFiles/pokebox.dir/flags.make
CMakeFiles/pokebox.dir/PokeType.c.o: ../PokeType.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/pokebox.dir/PokeType.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pokebox.dir/PokeType.c.o   -c "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/PokeType.c"

CMakeFiles/pokebox.dir/PokeType.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pokebox.dir/PokeType.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/PokeType.c" > CMakeFiles/pokebox.dir/PokeType.c.i

CMakeFiles/pokebox.dir/PokeType.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pokebox.dir/PokeType.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/PokeType.c" -o CMakeFiles/pokebox.dir/PokeType.c.s

CMakeFiles/pokebox.dir/utils.c.o: CMakeFiles/pokebox.dir/flags.make
CMakeFiles/pokebox.dir/utils.c.o: ../utils.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/pokebox.dir/utils.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/pokebox.dir/utils.c.o   -c "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/utils.c"

CMakeFiles/pokebox.dir/utils.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/pokebox.dir/utils.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/utils.c" > CMakeFiles/pokebox.dir/utils.c.i

CMakeFiles/pokebox.dir/utils.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/pokebox.dir/utils.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/utils.c" -o CMakeFiles/pokebox.dir/utils.c.s

# Object files for target pokebox
pokebox_OBJECTS = \
"CMakeFiles/pokebox.dir/main.c.o" \
"CMakeFiles/pokebox.dir/SaveManager.c.o" \
"CMakeFiles/pokebox.dir/dataStructures.c.o" \
"CMakeFiles/pokebox.dir/PokeBox.c.o" \
"CMakeFiles/pokebox.dir/Pokemon.c.o" \
"CMakeFiles/pokebox.dir/PokeDex.c.o" \
"CMakeFiles/pokebox.dir/SpriteManager.c.o" \
"CMakeFiles/pokebox.dir/Util.c.o" \
"CMakeFiles/pokebox.dir/PokeType.c.o" \
"CMakeFiles/pokebox.dir/utils.c.o"

# External object files for target pokebox
pokebox_EXTERNAL_OBJECTS =

pokebox: CMakeFiles/pokebox.dir/main.c.o
pokebox: CMakeFiles/pokebox.dir/SaveManager.c.o
pokebox: CMakeFiles/pokebox.dir/dataStructures.c.o
pokebox: CMakeFiles/pokebox.dir/PokeBox.c.o
pokebox: CMakeFiles/pokebox.dir/Pokemon.c.o
pokebox: CMakeFiles/pokebox.dir/PokeDex.c.o
pokebox: CMakeFiles/pokebox.dir/SpriteManager.c.o
pokebox: CMakeFiles/pokebox.dir/Util.c.o
pokebox: CMakeFiles/pokebox.dir/PokeType.c.o
pokebox: CMakeFiles/pokebox.dir/utils.c.o
pokebox: CMakeFiles/pokebox.dir/build.make
pokebox: CMakeFiles/pokebox.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_11) "Linking C executable pokebox"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pokebox.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pokebox.dir/build: pokebox

.PHONY : CMakeFiles/pokebox.dir/build

CMakeFiles/pokebox.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pokebox.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pokebox.dir/clean

CMakeFiles/pokebox.dir/depend:
	cd "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox" "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox" "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug" "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug" "/mnt/c/Users/maxse/Documents/Projects/CLion Projects (C)/pokebox/cmake-build-debug/CMakeFiles/pokebox.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/pokebox.dir/depend
