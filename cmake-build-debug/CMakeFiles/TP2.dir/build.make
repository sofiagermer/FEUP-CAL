# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/sofia/Desktop/CAL/CAL-Quickstart

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sofia/Desktop/CAL/CAL-Quickstart/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/TP2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/TP2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/TP2.dir/flags.make

CMakeFiles/TP2.dir/main.cpp.o: CMakeFiles/TP2.dir/flags.make
CMakeFiles/TP2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sofia/Desktop/CAL/CAL-Quickstart/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/TP2.dir/main.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2.dir/main.cpp.o -c /home/sofia/Desktop/CAL/CAL-Quickstart/main.cpp

CMakeFiles/TP2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sofia/Desktop/CAL/CAL-Quickstart/main.cpp > CMakeFiles/TP2.dir/main.cpp.i

CMakeFiles/TP2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sofia/Desktop/CAL/CAL-Quickstart/main.cpp -o CMakeFiles/TP2.dir/main.cpp.s

CMakeFiles/TP2.dir/TP2/ex1.cpp.o: CMakeFiles/TP2.dir/flags.make
CMakeFiles/TP2.dir/TP2/ex1.cpp.o: ../TP2/ex1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sofia/Desktop/CAL/CAL-Quickstart/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/TP2.dir/TP2/ex1.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2.dir/TP2/ex1.cpp.o -c /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex1.cpp

CMakeFiles/TP2.dir/TP2/ex1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2.dir/TP2/ex1.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex1.cpp > CMakeFiles/TP2.dir/TP2/ex1.cpp.i

CMakeFiles/TP2.dir/TP2/ex1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2.dir/TP2/ex1.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex1.cpp -o CMakeFiles/TP2.dir/TP2/ex1.cpp.s

CMakeFiles/TP2.dir/TP2/ex2.cpp.o: CMakeFiles/TP2.dir/flags.make
CMakeFiles/TP2.dir/TP2/ex2.cpp.o: ../TP2/ex2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sofia/Desktop/CAL/CAL-Quickstart/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/TP2.dir/TP2/ex2.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2.dir/TP2/ex2.cpp.o -c /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex2.cpp

CMakeFiles/TP2.dir/TP2/ex2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2.dir/TP2/ex2.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex2.cpp > CMakeFiles/TP2.dir/TP2/ex2.cpp.i

CMakeFiles/TP2.dir/TP2/ex2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2.dir/TP2/ex2.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex2.cpp -o CMakeFiles/TP2.dir/TP2/ex2.cpp.s

CMakeFiles/TP2.dir/TP2/ex3.cpp.o: CMakeFiles/TP2.dir/flags.make
CMakeFiles/TP2.dir/TP2/ex3.cpp.o: ../TP2/ex3.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sofia/Desktop/CAL/CAL-Quickstart/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/TP2.dir/TP2/ex3.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2.dir/TP2/ex3.cpp.o -c /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex3.cpp

CMakeFiles/TP2.dir/TP2/ex3.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2.dir/TP2/ex3.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex3.cpp > CMakeFiles/TP2.dir/TP2/ex3.cpp.i

CMakeFiles/TP2.dir/TP2/ex3.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2.dir/TP2/ex3.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex3.cpp -o CMakeFiles/TP2.dir/TP2/ex3.cpp.s

CMakeFiles/TP2.dir/TP2/ex4.cpp.o: CMakeFiles/TP2.dir/flags.make
CMakeFiles/TP2.dir/TP2/ex4.cpp.o: ../TP2/ex4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sofia/Desktop/CAL/CAL-Quickstart/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/TP2.dir/TP2/ex4.cpp.o"
	/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/TP2.dir/TP2/ex4.cpp.o -c /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex4.cpp

CMakeFiles/TP2.dir/TP2/ex4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/TP2.dir/TP2/ex4.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex4.cpp > CMakeFiles/TP2.dir/TP2/ex4.cpp.i

CMakeFiles/TP2.dir/TP2/ex4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/TP2.dir/TP2/ex4.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sofia/Desktop/CAL/CAL-Quickstart/TP2/ex4.cpp -o CMakeFiles/TP2.dir/TP2/ex4.cpp.s

# Object files for target TP2
TP2_OBJECTS = \
"CMakeFiles/TP2.dir/main.cpp.o" \
"CMakeFiles/TP2.dir/TP2/ex1.cpp.o" \
"CMakeFiles/TP2.dir/TP2/ex2.cpp.o" \
"CMakeFiles/TP2.dir/TP2/ex3.cpp.o" \
"CMakeFiles/TP2.dir/TP2/ex4.cpp.o"

# External object files for target TP2
TP2_EXTERNAL_OBJECTS =

TP2: CMakeFiles/TP2.dir/main.cpp.o
TP2: CMakeFiles/TP2.dir/TP2/ex1.cpp.o
TP2: CMakeFiles/TP2.dir/TP2/ex2.cpp.o
TP2: CMakeFiles/TP2.dir/TP2/ex3.cpp.o
TP2: CMakeFiles/TP2.dir/TP2/ex4.cpp.o
TP2: CMakeFiles/TP2.dir/build.make
TP2: lib/libgtest_maind.a
TP2: lib/libgmock_maind.a
TP2: lib/libgmockd.a
TP2: lib/libgtestd.a
TP2: CMakeFiles/TP2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sofia/Desktop/CAL/CAL-Quickstart/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable TP2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/TP2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/TP2.dir/build: TP2

.PHONY : CMakeFiles/TP2.dir/build

CMakeFiles/TP2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/TP2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/TP2.dir/clean

CMakeFiles/TP2.dir/depend:
	cd /home/sofia/Desktop/CAL/CAL-Quickstart/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sofia/Desktop/CAL/CAL-Quickstart /home/sofia/Desktop/CAL/CAL-Quickstart /home/sofia/Desktop/CAL/CAL-Quickstart/cmake-build-debug /home/sofia/Desktop/CAL/CAL-Quickstart/cmake-build-debug /home/sofia/Desktop/CAL/CAL-Quickstart/cmake-build-debug/CMakeFiles/TP2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/TP2.dir/depend

