# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen/build_folder

# Include any dependencies generated for this target.
include CMakeFiles/benchmarking_eratosfen.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/benchmarking_eratosfen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/benchmarking_eratosfen.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/benchmarking_eratosfen.dir/flags.make

CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.o: CMakeFiles/benchmarking_eratosfen.dir/flags.make
CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.o: /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen/benchmark_eratosfen.cpp
CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.o: CMakeFiles/benchmarking_eratosfen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen/build_folder/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.o -MF CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.o.d -o CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.o -c /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen/benchmark_eratosfen.cpp

CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen/benchmark_eratosfen.cpp > CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.i

CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen/benchmark_eratosfen.cpp -o CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.s

# Object files for target benchmarking_eratosfen
benchmarking_eratosfen_OBJECTS = \
"CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.o"

# External object files for target benchmarking_eratosfen
benchmarking_eratosfen_EXTERNAL_OBJECTS =

benchmarking_eratosfen: CMakeFiles/benchmarking_eratosfen.dir/benchmark_eratosfen.o
benchmarking_eratosfen: CMakeFiles/benchmarking_eratosfen.dir/build.make
benchmarking_eratosfen: CMakeFiles/benchmarking_eratosfen.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen/build_folder/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable benchmarking_eratosfen"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmarking_eratosfen.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/benchmarking_eratosfen.dir/build: benchmarking_eratosfen
.PHONY : CMakeFiles/benchmarking_eratosfen.dir/build

CMakeFiles/benchmarking_eratosfen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/benchmarking_eratosfen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/benchmarking_eratosfen.dir/clean

CMakeFiles/benchmarking_eratosfen.dir/depend:
	cd /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen/build_folder && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen/build_folder /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen/build_folder /home/mmm/Documents/VVEDENIE_V_PROGU/algosi_1/eratosfen/build_folder/CMakeFiles/benchmarking_eratosfen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/benchmarking_eratosfen.dir/depend

