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
CMAKE_SOURCE_DIR = "/home/romeowku/Рабочий стол/c++code/BattleShips"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/romeowku/Рабочий стол/c++code/BattleShips/build"

# Include any dependencies generated for this target.
include ShipCombined/CMakeFiles/ShipCombined.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include ShipCombined/CMakeFiles/ShipCombined.dir/compiler_depend.make

# Include the progress variables for this target.
include ShipCombined/CMakeFiles/ShipCombined.dir/progress.make

# Include the compile flags for this target's objects.
include ShipCombined/CMakeFiles/ShipCombined.dir/flags.make

ShipCombined/CMakeFiles/ShipCombined.dir/Ship.cpp.o: ShipCombined/CMakeFiles/ShipCombined.dir/flags.make
ShipCombined/CMakeFiles/ShipCombined.dir/Ship.cpp.o: /home/romeowku/Рабочий\ стол/c++code/BattleShips/ShipCombined/Ship.cpp
ShipCombined/CMakeFiles/ShipCombined.dir/Ship.cpp.o: ShipCombined/CMakeFiles/ShipCombined.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/romeowku/Рабочий стол/c++code/BattleShips/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object ShipCombined/CMakeFiles/ShipCombined.dir/Ship.cpp.o"
	cd "/home/romeowku/Рабочий стол/c++code/BattleShips/build/ShipCombined" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ShipCombined/CMakeFiles/ShipCombined.dir/Ship.cpp.o -MF CMakeFiles/ShipCombined.dir/Ship.cpp.o.d -o CMakeFiles/ShipCombined.dir/Ship.cpp.o -c "/home/romeowku/Рабочий стол/c++code/BattleShips/ShipCombined/Ship.cpp"

ShipCombined/CMakeFiles/ShipCombined.dir/Ship.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ShipCombined.dir/Ship.cpp.i"
	cd "/home/romeowku/Рабочий стол/c++code/BattleShips/build/ShipCombined" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/romeowku/Рабочий стол/c++code/BattleShips/ShipCombined/Ship.cpp" > CMakeFiles/ShipCombined.dir/Ship.cpp.i

ShipCombined/CMakeFiles/ShipCombined.dir/Ship.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ShipCombined.dir/Ship.cpp.s"
	cd "/home/romeowku/Рабочий стол/c++code/BattleShips/build/ShipCombined" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/romeowku/Рабочий стол/c++code/BattleShips/ShipCombined/Ship.cpp" -o CMakeFiles/ShipCombined.dir/Ship.cpp.s

ShipCombined/CMakeFiles/ShipCombined.dir/ShipManager.cpp.o: ShipCombined/CMakeFiles/ShipCombined.dir/flags.make
ShipCombined/CMakeFiles/ShipCombined.dir/ShipManager.cpp.o: /home/romeowku/Рабочий\ стол/c++code/BattleShips/ShipCombined/ShipManager.cpp
ShipCombined/CMakeFiles/ShipCombined.dir/ShipManager.cpp.o: ShipCombined/CMakeFiles/ShipCombined.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/home/romeowku/Рабочий стол/c++code/BattleShips/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object ShipCombined/CMakeFiles/ShipCombined.dir/ShipManager.cpp.o"
	cd "/home/romeowku/Рабочий стол/c++code/BattleShips/build/ShipCombined" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT ShipCombined/CMakeFiles/ShipCombined.dir/ShipManager.cpp.o -MF CMakeFiles/ShipCombined.dir/ShipManager.cpp.o.d -o CMakeFiles/ShipCombined.dir/ShipManager.cpp.o -c "/home/romeowku/Рабочий стол/c++code/BattleShips/ShipCombined/ShipManager.cpp"

ShipCombined/CMakeFiles/ShipCombined.dir/ShipManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/ShipCombined.dir/ShipManager.cpp.i"
	cd "/home/romeowku/Рабочий стол/c++code/BattleShips/build/ShipCombined" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/romeowku/Рабочий стол/c++code/BattleShips/ShipCombined/ShipManager.cpp" > CMakeFiles/ShipCombined.dir/ShipManager.cpp.i

ShipCombined/CMakeFiles/ShipCombined.dir/ShipManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/ShipCombined.dir/ShipManager.cpp.s"
	cd "/home/romeowku/Рабочий стол/c++code/BattleShips/build/ShipCombined" && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/romeowku/Рабочий стол/c++code/BattleShips/ShipCombined/ShipManager.cpp" -o CMakeFiles/ShipCombined.dir/ShipManager.cpp.s

# Object files for target ShipCombined
ShipCombined_OBJECTS = \
"CMakeFiles/ShipCombined.dir/Ship.cpp.o" \
"CMakeFiles/ShipCombined.dir/ShipManager.cpp.o"

# External object files for target ShipCombined
ShipCombined_EXTERNAL_OBJECTS =

ShipCombined/libShipCombined.a: ShipCombined/CMakeFiles/ShipCombined.dir/Ship.cpp.o
ShipCombined/libShipCombined.a: ShipCombined/CMakeFiles/ShipCombined.dir/ShipManager.cpp.o
ShipCombined/libShipCombined.a: ShipCombined/CMakeFiles/ShipCombined.dir/build.make
ShipCombined/libShipCombined.a: ShipCombined/CMakeFiles/ShipCombined.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/home/romeowku/Рабочий стол/c++code/BattleShips/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libShipCombined.a"
	cd "/home/romeowku/Рабочий стол/c++code/BattleShips/build/ShipCombined" && $(CMAKE_COMMAND) -P CMakeFiles/ShipCombined.dir/cmake_clean_target.cmake
	cd "/home/romeowku/Рабочий стол/c++code/BattleShips/build/ShipCombined" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ShipCombined.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
ShipCombined/CMakeFiles/ShipCombined.dir/build: ShipCombined/libShipCombined.a
.PHONY : ShipCombined/CMakeFiles/ShipCombined.dir/build

ShipCombined/CMakeFiles/ShipCombined.dir/clean:
	cd "/home/romeowku/Рабочий стол/c++code/BattleShips/build/ShipCombined" && $(CMAKE_COMMAND) -P CMakeFiles/ShipCombined.dir/cmake_clean.cmake
.PHONY : ShipCombined/CMakeFiles/ShipCombined.dir/clean

ShipCombined/CMakeFiles/ShipCombined.dir/depend:
	cd "/home/romeowku/Рабочий стол/c++code/BattleShips/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/romeowku/Рабочий стол/c++code/BattleShips" "/home/romeowku/Рабочий стол/c++code/BattleShips/ShipCombined" "/home/romeowku/Рабочий стол/c++code/BattleShips/build" "/home/romeowku/Рабочий стол/c++code/BattleShips/build/ShipCombined" "/home/romeowku/Рабочий стол/c++code/BattleShips/build/ShipCombined/CMakeFiles/ShipCombined.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : ShipCombined/CMakeFiles/ShipCombined.dir/depend

