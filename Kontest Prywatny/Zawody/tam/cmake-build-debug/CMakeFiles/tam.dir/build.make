# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /snap/clion/180/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/180/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/greeft/Kontest Prywatny/Zawody/tam"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/greeft/Kontest Prywatny/Zawody/tam/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/tam.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tam.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tam.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tam.dir/flags.make

CMakeFiles/tam.dir/main.cpp.o: CMakeFiles/tam.dir/flags.make
CMakeFiles/tam.dir/main.cpp.o: ../main.cpp
CMakeFiles/tam.dir/main.cpp.o: CMakeFiles/tam.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/greeft/Kontest Prywatny/Zawody/tam/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tam.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tam.dir/main.cpp.o -MF CMakeFiles/tam.dir/main.cpp.o.d -o CMakeFiles/tam.dir/main.cpp.o -c "/home/greeft/Kontest Prywatny/Zawody/tam/main.cpp"

CMakeFiles/tam.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tam.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/greeft/Kontest Prywatny/Zawody/tam/main.cpp" > CMakeFiles/tam.dir/main.cpp.i

CMakeFiles/tam.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tam.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/greeft/Kontest Prywatny/Zawody/tam/main.cpp" -o CMakeFiles/tam.dir/main.cpp.s

# Object files for target tam
tam_OBJECTS = \
"CMakeFiles/tam.dir/main.cpp.o"

# External object files for target tam
tam_EXTERNAL_OBJECTS =

tam: CMakeFiles/tam.dir/main.cpp.o
tam: CMakeFiles/tam.dir/build.make
tam: CMakeFiles/tam.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/greeft/Kontest Prywatny/Zawody/tam/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tam"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tam.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tam.dir/build: tam
.PHONY : CMakeFiles/tam.dir/build

CMakeFiles/tam.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tam.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tam.dir/clean

CMakeFiles/tam.dir/depend:
	cd "/home/greeft/Kontest Prywatny/Zawody/tam/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/greeft/Kontest Prywatny/Zawody/tam" "/home/greeft/Kontest Prywatny/Zawody/tam" "/home/greeft/Kontest Prywatny/Zawody/tam/cmake-build-debug" "/home/greeft/Kontest Prywatny/Zawody/tam/cmake-build-debug" "/home/greeft/Kontest Prywatny/Zawody/tam/cmake-build-debug/CMakeFiles/tam.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/tam.dir/depend

