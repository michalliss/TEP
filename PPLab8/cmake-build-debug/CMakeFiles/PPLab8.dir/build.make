# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /opt/clion/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/legusie/Documents/PWR/TEP/PPLab8

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/legusie/Documents/PWR/TEP/PPLab8/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/PPLab8.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PPLab8.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PPLab8.dir/flags.make

CMakeFiles/PPLab8.dir/main.cpp.o: CMakeFiles/PPLab8.dir/flags.make
CMakeFiles/PPLab8.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/legusie/Documents/PWR/TEP/PPLab8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PPLab8.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PPLab8.dir/main.cpp.o -c /home/legusie/Documents/PWR/TEP/PPLab8/main.cpp

CMakeFiles/PPLab8.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PPLab8.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/legusie/Documents/PWR/TEP/PPLab8/main.cpp > CMakeFiles/PPLab8.dir/main.cpp.i

CMakeFiles/PPLab8.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PPLab8.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/legusie/Documents/PWR/TEP/PPLab8/main.cpp -o CMakeFiles/PPLab8.dir/main.cpp.s

# Object files for target PPLab8
PPLab8_OBJECTS = \
"CMakeFiles/PPLab8.dir/main.cpp.o"

# External object files for target PPLab8
PPLab8_EXTERNAL_OBJECTS =

PPLab8: CMakeFiles/PPLab8.dir/main.cpp.o
PPLab8: CMakeFiles/PPLab8.dir/build.make
PPLab8: CMakeFiles/PPLab8.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/legusie/Documents/PWR/TEP/PPLab8/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable PPLab8"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PPLab8.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PPLab8.dir/build: PPLab8

.PHONY : CMakeFiles/PPLab8.dir/build

CMakeFiles/PPLab8.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PPLab8.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PPLab8.dir/clean

CMakeFiles/PPLab8.dir/depend:
	cd /home/legusie/Documents/PWR/TEP/PPLab8/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/legusie/Documents/PWR/TEP/PPLab8 /home/legusie/Documents/PWR/TEP/PPLab8 /home/legusie/Documents/PWR/TEP/PPLab8/cmake-build-debug /home/legusie/Documents/PWR/TEP/PPLab8/cmake-build-debug /home/legusie/Documents/PWR/TEP/PPLab8/cmake-build-debug/CMakeFiles/PPLab8.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PPLab8.dir/depend

