# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = F:\Environment\Cmake\bin\cmake.exe

# The command to remove a file.
RM = F:\Environment\Cmake\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\13152\Desktop\ScheduleAlgorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\13152\Desktop\ScheduleAlgorithm\build

# Include any dependencies generated for this target.
include CMakeFiles/example.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/example.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/example.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example.dir/flags.make

CMakeFiles/example.dir/project/test.cpp.obj: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/project/test.cpp.obj: CMakeFiles/example.dir/includes_CXX.rsp
CMakeFiles/example.dir/project/test.cpp.obj: ../project/test.cpp
CMakeFiles/example.dir/project/test.cpp.obj: CMakeFiles/example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\13152\Desktop\ScheduleAlgorithm\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/example.dir/project/test.cpp.obj"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/example.dir/project/test.cpp.obj -MF CMakeFiles\example.dir\project\test.cpp.obj.d -o CMakeFiles\example.dir\project\test.cpp.obj -c C:\Users\13152\Desktop\ScheduleAlgorithm\project\test.cpp

CMakeFiles/example.dir/project/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/project/test.cpp.i"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\13152\Desktop\ScheduleAlgorithm\project\test.cpp > CMakeFiles\example.dir\project\test.cpp.i

CMakeFiles/example.dir/project/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/project/test.cpp.s"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\13152\Desktop\ScheduleAlgorithm\project\test.cpp -o CMakeFiles\example.dir\project\test.cpp.s

CMakeFiles/example.dir/project/src/Course.cpp.obj: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/project/src/Course.cpp.obj: CMakeFiles/example.dir/includes_CXX.rsp
CMakeFiles/example.dir/project/src/Course.cpp.obj: ../project/src/Course.cpp
CMakeFiles/example.dir/project/src/Course.cpp.obj: CMakeFiles/example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\13152\Desktop\ScheduleAlgorithm\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/example.dir/project/src/Course.cpp.obj"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/example.dir/project/src/Course.cpp.obj -MF CMakeFiles\example.dir\project\src\Course.cpp.obj.d -o CMakeFiles\example.dir\project\src\Course.cpp.obj -c C:\Users\13152\Desktop\ScheduleAlgorithm\project\src\Course.cpp

CMakeFiles/example.dir/project/src/Course.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/project/src/Course.cpp.i"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\13152\Desktop\ScheduleAlgorithm\project\src\Course.cpp > CMakeFiles\example.dir\project\src\Course.cpp.i

CMakeFiles/example.dir/project/src/Course.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/project/src/Course.cpp.s"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\13152\Desktop\ScheduleAlgorithm\project\src\Course.cpp -o CMakeFiles\example.dir\project\src\Course.cpp.s

CMakeFiles/example.dir/project/src/Schedule.cpp.obj: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/project/src/Schedule.cpp.obj: CMakeFiles/example.dir/includes_CXX.rsp
CMakeFiles/example.dir/project/src/Schedule.cpp.obj: ../project/src/Schedule.cpp
CMakeFiles/example.dir/project/src/Schedule.cpp.obj: CMakeFiles/example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\13152\Desktop\ScheduleAlgorithm\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/example.dir/project/src/Schedule.cpp.obj"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/example.dir/project/src/Schedule.cpp.obj -MF CMakeFiles\example.dir\project\src\Schedule.cpp.obj.d -o CMakeFiles\example.dir\project\src\Schedule.cpp.obj -c C:\Users\13152\Desktop\ScheduleAlgorithm\project\src\Schedule.cpp

CMakeFiles/example.dir/project/src/Schedule.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/project/src/Schedule.cpp.i"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\13152\Desktop\ScheduleAlgorithm\project\src\Schedule.cpp > CMakeFiles\example.dir\project\src\Schedule.cpp.i

CMakeFiles/example.dir/project/src/Schedule.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/project/src/Schedule.cpp.s"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\13152\Desktop\ScheduleAlgorithm\project\src\Schedule.cpp -o CMakeFiles\example.dir\project\src\Schedule.cpp.s

CMakeFiles/example.dir/project/src/ScheduleManager.cpp.obj: CMakeFiles/example.dir/flags.make
CMakeFiles/example.dir/project/src/ScheduleManager.cpp.obj: CMakeFiles/example.dir/includes_CXX.rsp
CMakeFiles/example.dir/project/src/ScheduleManager.cpp.obj: ../project/src/ScheduleManager.cpp
CMakeFiles/example.dir/project/src/ScheduleManager.cpp.obj: CMakeFiles/example.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\13152\Desktop\ScheduleAlgorithm\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/example.dir/project/src/ScheduleManager.cpp.obj"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/example.dir/project/src/ScheduleManager.cpp.obj -MF CMakeFiles\example.dir\project\src\ScheduleManager.cpp.obj.d -o CMakeFiles\example.dir\project\src\ScheduleManager.cpp.obj -c C:\Users\13152\Desktop\ScheduleAlgorithm\project\src\ScheduleManager.cpp

CMakeFiles/example.dir/project/src/ScheduleManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example.dir/project/src/ScheduleManager.cpp.i"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\13152\Desktop\ScheduleAlgorithm\project\src\ScheduleManager.cpp > CMakeFiles\example.dir\project\src\ScheduleManager.cpp.i

CMakeFiles/example.dir/project/src/ScheduleManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example.dir/project/src/ScheduleManager.cpp.s"
	F:\Environment\mingw64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\13152\Desktop\ScheduleAlgorithm\project\src\ScheduleManager.cpp -o CMakeFiles\example.dir\project\src\ScheduleManager.cpp.s

# Object files for target example
example_OBJECTS = \
"CMakeFiles/example.dir/project/test.cpp.obj" \
"CMakeFiles/example.dir/project/src/Course.cpp.obj" \
"CMakeFiles/example.dir/project/src/Schedule.cpp.obj" \
"CMakeFiles/example.dir/project/src/ScheduleManager.cpp.obj"

# External object files for target example
example_EXTERNAL_OBJECTS =

example.exe: CMakeFiles/example.dir/project/test.cpp.obj
example.exe: CMakeFiles/example.dir/project/src/Course.cpp.obj
example.exe: CMakeFiles/example.dir/project/src/Schedule.cpp.obj
example.exe: CMakeFiles/example.dir/project/src/ScheduleManager.cpp.obj
example.exe: CMakeFiles/example.dir/build.make
example.exe: CMakeFiles/example.dir/linklibs.rsp
example.exe: CMakeFiles/example.dir/objects1.rsp
example.exe: CMakeFiles/example.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\13152\Desktop\ScheduleAlgorithm\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable example.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\example.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example.dir/build: example.exe
.PHONY : CMakeFiles/example.dir/build

CMakeFiles/example.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\example.dir\cmake_clean.cmake
.PHONY : CMakeFiles/example.dir/clean

CMakeFiles/example.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\13152\Desktop\ScheduleAlgorithm C:\Users\13152\Desktop\ScheduleAlgorithm C:\Users\13152\Desktop\ScheduleAlgorithm\build C:\Users\13152\Desktop\ScheduleAlgorithm\build C:\Users\13152\Desktop\ScheduleAlgorithm\build\CMakeFiles\example.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example.dir/depend
