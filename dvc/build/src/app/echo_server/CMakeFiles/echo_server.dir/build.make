# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_SOURCE_DIR = /mnt/work/mime/code/dvc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/work/mime/code/dvc/build

# Include any dependencies generated for this target.
include src/app/echo_server/CMakeFiles/echo_server.dir/depend.make

# Include the progress variables for this target.
include src/app/echo_server/CMakeFiles/echo_server.dir/progress.make

# Include the compile flags for this target's objects.
include src/app/echo_server/CMakeFiles/echo_server.dir/flags.make

src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o: src/app/echo_server/CMakeFiles/echo_server.dir/flags.make
src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o: ../src/app/echo_server/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/work/mime/code/dvc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o"
	cd /mnt/work/mime/code/dvc/build/src/app/echo_server && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/echo_server.dir/main.cpp.o -c /mnt/work/mime/code/dvc/src/app/echo_server/main.cpp

src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/echo_server.dir/main.cpp.i"
	cd /mnt/work/mime/code/dvc/build/src/app/echo_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/work/mime/code/dvc/src/app/echo_server/main.cpp > CMakeFiles/echo_server.dir/main.cpp.i

src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/echo_server.dir/main.cpp.s"
	cd /mnt/work/mime/code/dvc/build/src/app/echo_server && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/work/mime/code/dvc/src/app/echo_server/main.cpp -o CMakeFiles/echo_server.dir/main.cpp.s

src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o.requires:

.PHONY : src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o.requires

src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o.provides: src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o.requires
	$(MAKE) -f src/app/echo_server/CMakeFiles/echo_server.dir/build.make src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o.provides.build
.PHONY : src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o.provides

src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o.provides.build: src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o


# Object files for target echo_server
echo_server_OBJECTS = \
"CMakeFiles/echo_server.dir/main.cpp.o"

# External object files for target echo_server
echo_server_EXTERNAL_OBJECTS =

../bin/echo_server: src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o
../bin/echo_server: src/app/echo_server/CMakeFiles/echo_server.dir/build.make
../bin/echo_server: src/app/echo_server/CMakeFiles/echo_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/work/mime/code/dvc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../../bin/echo_server"
	cd /mnt/work/mime/code/dvc/build/src/app/echo_server && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/echo_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/app/echo_server/CMakeFiles/echo_server.dir/build: ../bin/echo_server

.PHONY : src/app/echo_server/CMakeFiles/echo_server.dir/build

src/app/echo_server/CMakeFiles/echo_server.dir/requires: src/app/echo_server/CMakeFiles/echo_server.dir/main.cpp.o.requires

.PHONY : src/app/echo_server/CMakeFiles/echo_server.dir/requires

src/app/echo_server/CMakeFiles/echo_server.dir/clean:
	cd /mnt/work/mime/code/dvc/build/src/app/echo_server && $(CMAKE_COMMAND) -P CMakeFiles/echo_server.dir/cmake_clean.cmake
.PHONY : src/app/echo_server/CMakeFiles/echo_server.dir/clean

src/app/echo_server/CMakeFiles/echo_server.dir/depend:
	cd /mnt/work/mime/code/dvc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/work/mime/code/dvc /mnt/work/mime/code/dvc/src/app/echo_server /mnt/work/mime/code/dvc/build /mnt/work/mime/code/dvc/build/src/app/echo_server /mnt/work/mime/code/dvc/build/src/app/echo_server/CMakeFiles/echo_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/app/echo_server/CMakeFiles/echo_server.dir/depend

