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
CMAKE_COMMAND = /home/mtm/cmake-3.17.0-Linux-x86_64/bin/cmake

# The command to remove a file.
RM = /home/mtm/cmake-3.17.0-Linux-x86_64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/uri.yakar/Mivni/Hw1/BoomCourseManager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/uri.yakar/Mivni/Hw1/BoomCourseManager/build

# Include any dependencies generated for this target.
include CMakeFiles/Boom.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Boom.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Boom.dir/flags.make

CMakeFiles/Boom.dir/main.cpp.o: CMakeFiles/Boom.dir/flags.make
CMakeFiles/Boom.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uri.yakar/Mivni/Hw1/BoomCourseManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Boom.dir/main.cpp.o"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boom.dir/main.cpp.o -c /home/uri.yakar/Mivni/Hw1/BoomCourseManager/main.cpp

CMakeFiles/Boom.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boom.dir/main.cpp.i"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uri.yakar/Mivni/Hw1/BoomCourseManager/main.cpp > CMakeFiles/Boom.dir/main.cpp.i

CMakeFiles/Boom.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boom.dir/main.cpp.s"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uri.yakar/Mivni/Hw1/BoomCourseManager/main.cpp -o CMakeFiles/Boom.dir/main.cpp.s

CMakeFiles/Boom.dir/AVLTree.cpp.o: CMakeFiles/Boom.dir/flags.make
CMakeFiles/Boom.dir/AVLTree.cpp.o: ../AVLTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uri.yakar/Mivni/Hw1/BoomCourseManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Boom.dir/AVLTree.cpp.o"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boom.dir/AVLTree.cpp.o -c /home/uri.yakar/Mivni/Hw1/BoomCourseManager/AVLTree.cpp

CMakeFiles/Boom.dir/AVLTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boom.dir/AVLTree.cpp.i"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uri.yakar/Mivni/Hw1/BoomCourseManager/AVLTree.cpp > CMakeFiles/Boom.dir/AVLTree.cpp.i

CMakeFiles/Boom.dir/AVLTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boom.dir/AVLTree.cpp.s"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uri.yakar/Mivni/Hw1/BoomCourseManager/AVLTree.cpp -o CMakeFiles/Boom.dir/AVLTree.cpp.s

CMakeFiles/Boom.dir/AVLNode.cpp.o: CMakeFiles/Boom.dir/flags.make
CMakeFiles/Boom.dir/AVLNode.cpp.o: ../AVLNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uri.yakar/Mivni/Hw1/BoomCourseManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Boom.dir/AVLNode.cpp.o"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boom.dir/AVLNode.cpp.o -c /home/uri.yakar/Mivni/Hw1/BoomCourseManager/AVLNode.cpp

CMakeFiles/Boom.dir/AVLNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boom.dir/AVLNode.cpp.i"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uri.yakar/Mivni/Hw1/BoomCourseManager/AVLNode.cpp > CMakeFiles/Boom.dir/AVLNode.cpp.i

CMakeFiles/Boom.dir/AVLNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boom.dir/AVLNode.cpp.s"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uri.yakar/Mivni/Hw1/BoomCourseManager/AVLNode.cpp -o CMakeFiles/Boom.dir/AVLNode.cpp.s

CMakeFiles/Boom.dir/Auxiliaries.cpp.o: CMakeFiles/Boom.dir/flags.make
CMakeFiles/Boom.dir/Auxiliaries.cpp.o: ../Auxiliaries.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/uri.yakar/Mivni/Hw1/BoomCourseManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Boom.dir/Auxiliaries.cpp.o"
	/usr/local/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Boom.dir/Auxiliaries.cpp.o -c /home/uri.yakar/Mivni/Hw1/BoomCourseManager/Auxiliaries.cpp

CMakeFiles/Boom.dir/Auxiliaries.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Boom.dir/Auxiliaries.cpp.i"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/uri.yakar/Mivni/Hw1/BoomCourseManager/Auxiliaries.cpp > CMakeFiles/Boom.dir/Auxiliaries.cpp.i

CMakeFiles/Boom.dir/Auxiliaries.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Boom.dir/Auxiliaries.cpp.s"
	/usr/local/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/uri.yakar/Mivni/Hw1/BoomCourseManager/Auxiliaries.cpp -o CMakeFiles/Boom.dir/Auxiliaries.cpp.s

# Object files for target Boom
Boom_OBJECTS = \
"CMakeFiles/Boom.dir/main.cpp.o" \
"CMakeFiles/Boom.dir/AVLTree.cpp.o" \
"CMakeFiles/Boom.dir/AVLNode.cpp.o" \
"CMakeFiles/Boom.dir/Auxiliaries.cpp.o"

# External object files for target Boom
Boom_EXTERNAL_OBJECTS =

Boom: CMakeFiles/Boom.dir/main.cpp.o
Boom: CMakeFiles/Boom.dir/AVLTree.cpp.o
Boom: CMakeFiles/Boom.dir/AVLNode.cpp.o
Boom: CMakeFiles/Boom.dir/Auxiliaries.cpp.o
Boom: CMakeFiles/Boom.dir/build.make
Boom: CMakeFiles/Boom.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/uri.yakar/Mivni/Hw1/BoomCourseManager/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable Boom"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Boom.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Boom.dir/build: Boom

.PHONY : CMakeFiles/Boom.dir/build

CMakeFiles/Boom.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Boom.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Boom.dir/clean

CMakeFiles/Boom.dir/depend:
	cd /home/uri.yakar/Mivni/Hw1/BoomCourseManager/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/uri.yakar/Mivni/Hw1/BoomCourseManager /home/uri.yakar/Mivni/Hw1/BoomCourseManager /home/uri.yakar/Mivni/Hw1/BoomCourseManager/build /home/uri.yakar/Mivni/Hw1/BoomCourseManager/build /home/uri.yakar/Mivni/Hw1/BoomCourseManager/build/CMakeFiles/Boom.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Boom.dir/depend

