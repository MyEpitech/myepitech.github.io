# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build

# Include any dependencies generated for this target.
include boost/libs/atomic/CMakeFiles/boost_atomic.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include boost/libs/atomic/CMakeFiles/boost_atomic.dir/compiler_depend.make

# Include the progress variables for this target.
include boost/libs/atomic/CMakeFiles/boost_atomic.dir/progress.make

# Include the compile flags for this target's objects.
include boost/libs/atomic/CMakeFiles/boost_atomic.dir/flags.make

boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.o: boost/libs/atomic/CMakeFiles/boost_atomic.dir/flags.make
boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.o: ../boost/libs/atomic/src/lock_pool.cpp
boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.o: boost/libs/atomic/CMakeFiles/boost_atomic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.o"
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.o -MF CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.o.d -o CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.o -c /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/boost/libs/atomic/src/lock_pool.cpp

boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.i"
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/boost/libs/atomic/src/lock_pool.cpp > CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.i

boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.s"
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/boost/libs/atomic/src/lock_pool.cpp -o CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.s

boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.o: boost/libs/atomic/CMakeFiles/boost_atomic.dir/flags.make
boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.o: ../boost/libs/atomic/src/find_address_sse2.cpp
boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.o: boost/libs/atomic/CMakeFiles/boost_atomic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.o"
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -msse -msse2 -MD -MT boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.o -MF CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.o.d -o CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.o -c /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/boost/libs/atomic/src/find_address_sse2.cpp

boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.i"
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -msse -msse2 -E /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/boost/libs/atomic/src/find_address_sse2.cpp > CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.i

boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.s"
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -msse -msse2 -S /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/boost/libs/atomic/src/find_address_sse2.cpp -o CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.s

boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.o: boost/libs/atomic/CMakeFiles/boost_atomic.dir/flags.make
boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.o: ../boost/libs/atomic/src/find_address_sse41.cpp
boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.o: boost/libs/atomic/CMakeFiles/boost_atomic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.o"
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -msse -msse2 -msse3 -mssse3 -msse4.1 -MD -MT boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.o -MF CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.o.d -o CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.o -c /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/boost/libs/atomic/src/find_address_sse41.cpp

boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.i"
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -msse -msse2 -msse3 -mssse3 -msse4.1 -E /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/boost/libs/atomic/src/find_address_sse41.cpp > CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.i

boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.s"
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -msse -msse2 -msse3 -mssse3 -msse4.1 -S /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/boost/libs/atomic/src/find_address_sse41.cpp -o CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.s

# Object files for target boost_atomic
boost_atomic_OBJECTS = \
"CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.o" \
"CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.o" \
"CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.o"

# External object files for target boost_atomic
boost_atomic_EXTERNAL_OBJECTS =

boost/libs/atomic/libboost_atomic.a: boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/lock_pool.cpp.o
boost/libs/atomic/libboost_atomic.a: boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse2.cpp.o
boost/libs/atomic/libboost_atomic.a: boost/libs/atomic/CMakeFiles/boost_atomic.dir/src/find_address_sse41.cpp.o
boost/libs/atomic/libboost_atomic.a: boost/libs/atomic/CMakeFiles/boost_atomic.dir/build.make
boost/libs/atomic/libboost_atomic.a: boost/libs/atomic/CMakeFiles/boost_atomic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX static library libboost_atomic.a"
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && $(CMAKE_COMMAND) -P CMakeFiles/boost_atomic.dir/cmake_clean_target.cmake
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/boost_atomic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
boost/libs/atomic/CMakeFiles/boost_atomic.dir/build: boost/libs/atomic/libboost_atomic.a
.PHONY : boost/libs/atomic/CMakeFiles/boost_atomic.dir/build

boost/libs/atomic/CMakeFiles/boost_atomic.dir/clean:
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic && $(CMAKE_COMMAND) -P CMakeFiles/boost_atomic.dir/cmake_clean.cmake
.PHONY : boost/libs/atomic/CMakeFiles/boost_atomic.dir/clean

boost/libs/atomic/CMakeFiles/boost_atomic.dir/depend:
	cd /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/boost/libs/atomic /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic /home/manulop/delivery/Semestre_5/B-CPP-500-PAR-5-1-rtype-martin.vanaud/build/boost/libs/atomic/CMakeFiles/boost_atomic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : boost/libs/atomic/CMakeFiles/boost_atomic.dir/depend

