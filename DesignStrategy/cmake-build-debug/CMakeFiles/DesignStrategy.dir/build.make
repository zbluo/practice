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
CMAKE_COMMAND = "/Applications/CLion 2.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Applications/CLion 2.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/zbing/CLionProjects/DesignStrategy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/zbing/CLionProjects/DesignStrategy/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DesignStrategy.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DesignStrategy.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DesignStrategy.dir/flags.make

CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.o: CMakeFiles/DesignStrategy.dir/flags.make
CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.o: ../ThreadPool.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/zbing/CLionProjects/DesignStrategy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.o -c /Users/zbing/CLionProjects/DesignStrategy/ThreadPool.cpp

CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/zbing/CLionProjects/DesignStrategy/ThreadPool.cpp > CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.i

CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/zbing/CLionProjects/DesignStrategy/ThreadPool.cpp -o CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.s

# Object files for target DesignStrategy
DesignStrategy_OBJECTS = \
"CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.o"

# External object files for target DesignStrategy
DesignStrategy_EXTERNAL_OBJECTS =

DesignStrategy: CMakeFiles/DesignStrategy.dir/ThreadPool.cpp.o
DesignStrategy: CMakeFiles/DesignStrategy.dir/build.make
DesignStrategy: CMakeFiles/DesignStrategy.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/zbing/CLionProjects/DesignStrategy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DesignStrategy"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/DesignStrategy.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DesignStrategy.dir/build: DesignStrategy

.PHONY : CMakeFiles/DesignStrategy.dir/build

CMakeFiles/DesignStrategy.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/DesignStrategy.dir/cmake_clean.cmake
.PHONY : CMakeFiles/DesignStrategy.dir/clean

CMakeFiles/DesignStrategy.dir/depend:
	cd /Users/zbing/CLionProjects/DesignStrategy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/zbing/CLionProjects/DesignStrategy /Users/zbing/CLionProjects/DesignStrategy /Users/zbing/CLionProjects/DesignStrategy/cmake-build-debug /Users/zbing/CLionProjects/DesignStrategy/cmake-build-debug /Users/zbing/CLionProjects/DesignStrategy/cmake-build-debug/CMakeFiles/DesignStrategy.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DesignStrategy.dir/depend

