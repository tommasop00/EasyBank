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
CMAKE_COMMAND = /snap/clion/129/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/129/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tommaso/Scrivania/CLionProject/EasyBank

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tommaso/Scrivania/CLionProject/EasyBank/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/EasyBank.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EasyBank.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EasyBank.dir/flags.make

CMakeFiles/EasyBank.dir/main.cpp.o: CMakeFiles/EasyBank.dir/flags.make
CMakeFiles/EasyBank.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tommaso/Scrivania/CLionProject/EasyBank/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EasyBank.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/EasyBank.dir/main.cpp.o -c /home/tommaso/Scrivania/CLionProject/EasyBank/main.cpp

CMakeFiles/EasyBank.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EasyBank.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tommaso/Scrivania/CLionProject/EasyBank/main.cpp > CMakeFiles/EasyBank.dir/main.cpp.i

CMakeFiles/EasyBank.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EasyBank.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tommaso/Scrivania/CLionProject/EasyBank/main.cpp -o CMakeFiles/EasyBank.dir/main.cpp.s

# Object files for target EasyBank
EasyBank_OBJECTS = \
"CMakeFiles/EasyBank.dir/main.cpp.o"

# External object files for target EasyBank
EasyBank_EXTERNAL_OBJECTS =

EasyBank: CMakeFiles/EasyBank.dir/main.cpp.o
EasyBank: CMakeFiles/EasyBank.dir/build.make
EasyBank: CMakeFiles/EasyBank.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tommaso/Scrivania/CLionProject/EasyBank/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable EasyBank"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EasyBank.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EasyBank.dir/build: EasyBank

.PHONY : CMakeFiles/EasyBank.dir/build

CMakeFiles/EasyBank.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EasyBank.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EasyBank.dir/clean

CMakeFiles/EasyBank.dir/depend:
	cd /home/tommaso/Scrivania/CLionProject/EasyBank/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tommaso/Scrivania/CLionProject/EasyBank /home/tommaso/Scrivania/CLionProject/EasyBank /home/tommaso/Scrivania/CLionProject/EasyBank/cmake-build-debug /home/tommaso/Scrivania/CLionProject/EasyBank/cmake-build-debug /home/tommaso/Scrivania/CLionProject/EasyBank/cmake-build-debug/CMakeFiles/EasyBank.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EasyBank.dir/depend

