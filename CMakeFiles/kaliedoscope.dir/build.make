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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.28.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.28.1/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/chuckzumbaugh/Documents/kaliedoscope

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/chuckzumbaugh/Documents/kaliedoscope

# Include any dependencies generated for this target.
include CMakeFiles/kaliedoscope.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/kaliedoscope.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/kaliedoscope.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kaliedoscope.dir/flags.make

CMakeFiles/kaliedoscope.dir/main.cpp.o: CMakeFiles/kaliedoscope.dir/flags.make
CMakeFiles/kaliedoscope.dir/main.cpp.o: main.cpp
CMakeFiles/kaliedoscope.dir/main.cpp.o: CMakeFiles/kaliedoscope.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kaliedoscope.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kaliedoscope.dir/main.cpp.o -MF CMakeFiles/kaliedoscope.dir/main.cpp.o.d -o CMakeFiles/kaliedoscope.dir/main.cpp.o -c /Users/chuckzumbaugh/Documents/kaliedoscope/main.cpp

CMakeFiles/kaliedoscope.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kaliedoscope.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chuckzumbaugh/Documents/kaliedoscope/main.cpp > CMakeFiles/kaliedoscope.dir/main.cpp.i

CMakeFiles/kaliedoscope.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kaliedoscope.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chuckzumbaugh/Documents/kaliedoscope/main.cpp -o CMakeFiles/kaliedoscope.dir/main.cpp.s

CMakeFiles/kaliedoscope.dir/lexer.cpp.o: CMakeFiles/kaliedoscope.dir/flags.make
CMakeFiles/kaliedoscope.dir/lexer.cpp.o: lexer.cpp
CMakeFiles/kaliedoscope.dir/lexer.cpp.o: CMakeFiles/kaliedoscope.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/kaliedoscope.dir/lexer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kaliedoscope.dir/lexer.cpp.o -MF CMakeFiles/kaliedoscope.dir/lexer.cpp.o.d -o CMakeFiles/kaliedoscope.dir/lexer.cpp.o -c /Users/chuckzumbaugh/Documents/kaliedoscope/lexer.cpp

CMakeFiles/kaliedoscope.dir/lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kaliedoscope.dir/lexer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chuckzumbaugh/Documents/kaliedoscope/lexer.cpp > CMakeFiles/kaliedoscope.dir/lexer.cpp.i

CMakeFiles/kaliedoscope.dir/lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kaliedoscope.dir/lexer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chuckzumbaugh/Documents/kaliedoscope/lexer.cpp -o CMakeFiles/kaliedoscope.dir/lexer.cpp.s

CMakeFiles/kaliedoscope.dir/parser.cpp.o: CMakeFiles/kaliedoscope.dir/flags.make
CMakeFiles/kaliedoscope.dir/parser.cpp.o: parser.cpp
CMakeFiles/kaliedoscope.dir/parser.cpp.o: CMakeFiles/kaliedoscope.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/kaliedoscope.dir/parser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kaliedoscope.dir/parser.cpp.o -MF CMakeFiles/kaliedoscope.dir/parser.cpp.o.d -o CMakeFiles/kaliedoscope.dir/parser.cpp.o -c /Users/chuckzumbaugh/Documents/kaliedoscope/parser.cpp

CMakeFiles/kaliedoscope.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kaliedoscope.dir/parser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/chuckzumbaugh/Documents/kaliedoscope/parser.cpp > CMakeFiles/kaliedoscope.dir/parser.cpp.i

CMakeFiles/kaliedoscope.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kaliedoscope.dir/parser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/chuckzumbaugh/Documents/kaliedoscope/parser.cpp -o CMakeFiles/kaliedoscope.dir/parser.cpp.s

CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.o: CMakeFiles/kaliedoscope.dir/flags.make
CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.o: AST\ Nodes/ExprAST.cpp
CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.o: CMakeFiles/kaliedoscope.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.o -MF CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.o.d -o CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.o -c "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/ExprAST.cpp"

CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/ExprAST.cpp" > CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.i

CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/ExprAST.cpp" -o CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.s

CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.o: CMakeFiles/kaliedoscope.dir/flags.make
CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.o: AST\ Nodes/NumberExprAST.cpp
CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.o: CMakeFiles/kaliedoscope.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.o -MF CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.o.d -o CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.o -c "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/NumberExprAST.cpp"

CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/NumberExprAST.cpp" > CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.i

CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/NumberExprAST.cpp" -o CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.s

CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.o: CMakeFiles/kaliedoscope.dir/flags.make
CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.o: AST\ Nodes/VariableExprAST.cpp
CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.o: CMakeFiles/kaliedoscope.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.o -MF CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.o.d -o CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.o -c "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/VariableExprAST.cpp"

CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/VariableExprAST.cpp" > CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.i

CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/VariableExprAST.cpp" -o CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.s

CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.o: CMakeFiles/kaliedoscope.dir/flags.make
CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.o: AST\ Nodes/BinaryExprAST.cpp
CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.o: CMakeFiles/kaliedoscope.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.o -MF CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.o.d -o CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.o -c "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/BinaryExprAST.cpp"

CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/BinaryExprAST.cpp" > CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.i

CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/BinaryExprAST.cpp" -o CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.s

CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.o: CMakeFiles/kaliedoscope.dir/flags.make
CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.o: AST\ Nodes/CallExprAST.cpp
CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.o: CMakeFiles/kaliedoscope.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.o -MF CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.o.d -o CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.o -c "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/CallExprAST.cpp"

CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/CallExprAST.cpp" > CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.i

CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/CallExprAST.cpp" -o CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.s

CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.o: CMakeFiles/kaliedoscope.dir/flags.make
CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.o: AST\ Nodes/PrototypeAST.cpp
CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.o: CMakeFiles/kaliedoscope.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.o -MF CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.o.d -o CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.o -c "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/PrototypeAST.cpp"

CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/PrototypeAST.cpp" > CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.i

CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/PrototypeAST.cpp" -o CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.s

CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.o: CMakeFiles/kaliedoscope.dir/flags.make
CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.o: AST\ Nodes/FunctionAST.cpp
CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.o: CMakeFiles/kaliedoscope.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.o -MF CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.o.d -o CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.o -c "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/FunctionAST.cpp"

CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/FunctionAST.cpp" > CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.i

CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/chuckzumbaugh/Documents/kaliedoscope/AST Nodes/FunctionAST.cpp" -o CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.s

# Object files for target kaliedoscope
kaliedoscope_OBJECTS = \
"CMakeFiles/kaliedoscope.dir/main.cpp.o" \
"CMakeFiles/kaliedoscope.dir/lexer.cpp.o" \
"CMakeFiles/kaliedoscope.dir/parser.cpp.o" \
"CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.o" \
"CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.o" \
"CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.o" \
"CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.o" \
"CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.o" \
"CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.o" \
"CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.o"

# External object files for target kaliedoscope
kaliedoscope_EXTERNAL_OBJECTS =

kaliedoscope: CMakeFiles/kaliedoscope.dir/main.cpp.o
kaliedoscope: CMakeFiles/kaliedoscope.dir/lexer.cpp.o
kaliedoscope: CMakeFiles/kaliedoscope.dir/parser.cpp.o
kaliedoscope: CMakeFiles/kaliedoscope.dir/AST_Nodes/ExprAST.cpp.o
kaliedoscope: CMakeFiles/kaliedoscope.dir/AST_Nodes/NumberExprAST.cpp.o
kaliedoscope: CMakeFiles/kaliedoscope.dir/AST_Nodes/VariableExprAST.cpp.o
kaliedoscope: CMakeFiles/kaliedoscope.dir/AST_Nodes/BinaryExprAST.cpp.o
kaliedoscope: CMakeFiles/kaliedoscope.dir/AST_Nodes/CallExprAST.cpp.o
kaliedoscope: CMakeFiles/kaliedoscope.dir/AST_Nodes/PrototypeAST.cpp.o
kaliedoscope: CMakeFiles/kaliedoscope.dir/AST_Nodes/FunctionAST.cpp.o
kaliedoscope: CMakeFiles/kaliedoscope.dir/build.make
kaliedoscope: CMakeFiles/kaliedoscope.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Linking CXX executable kaliedoscope"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kaliedoscope.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kaliedoscope.dir/build: kaliedoscope
.PHONY : CMakeFiles/kaliedoscope.dir/build

CMakeFiles/kaliedoscope.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kaliedoscope.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kaliedoscope.dir/clean

CMakeFiles/kaliedoscope.dir/depend:
	cd /Users/chuckzumbaugh/Documents/kaliedoscope && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/chuckzumbaugh/Documents/kaliedoscope /Users/chuckzumbaugh/Documents/kaliedoscope /Users/chuckzumbaugh/Documents/kaliedoscope /Users/chuckzumbaugh/Documents/kaliedoscope /Users/chuckzumbaugh/Documents/kaliedoscope/CMakeFiles/kaliedoscope.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/kaliedoscope.dir/depend

