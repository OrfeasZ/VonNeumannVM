# Compiler flags...
CPP_COMPILER = g++
C_COMPILER = gcc

# Include paths...
Debug_Include_Path=
Release_Include_Path=

# Library paths...
Debug_Library_Path=
Release_Library_Path=

# Additional libraries...
Debug_Libraries=
Release_Libraries=

# Preprocessor definitions...
Debug_Preprocessor_Definitions=-D GCC_BUILD -D _DEBUG -D _CONSOLE 
Release_Preprocessor_Definitions=-D GCC_BUILD -D NDEBUG -D _CONSOLE 

# Implictly linked object files...
Debug_Implicitly_Linked_Objects=
Release_Implicitly_Linked_Objects=

# Compiler flags...
Debug_Compiler_Flags=-O0 -g 
Release_Compiler_Flags=-O2 

# Builds all configurations for this project...
.PHONY: build_all_configurations
build_all_configurations: Debug Release 

# Builds the Debug configuration...
.PHONY: Debug
Debug: create_folders gccDebug/Src/DataBus.o gccDebug/Src/Registers/Accumulator.o gccDebug/Src/ALU.o gccDebug/Src/ControlUnit.o gccDebug/Src/CPU.o gccDebug/Src/Memory.o gccDebug/Src/Multiplexer.o gccDebug/Src/OpcodeConverter.o gccDebug/Src/Operation.o gccDebug/Src/Registers/DataRegister.o gccDebug/Src/Registers/InstructionRegister.o gccDebug/Src/Registers/OutputRegister.o gccDebug/Src/Registers/ProgramCounter.o gccDebug/Src/Registers/Register.o gccDebug/Src/VonNeumannVM.o gccDebug/Src/VM.o 
	g++ gccDebug/Src/DataBus.o gccDebug/Src/Registers/Accumulator.o gccDebug/Src/ALU.o gccDebug/Src/ControlUnit.o gccDebug/Src/CPU.o gccDebug/Src/Memory.o gccDebug/Src/Multiplexer.o gccDebug/Src/OpcodeConverter.o gccDebug/Src/Operation.o gccDebug/Src/Registers/DataRegister.o gccDebug/Src/Registers/InstructionRegister.o gccDebug/Src/Registers/OutputRegister.o gccDebug/Src/Registers/ProgramCounter.o gccDebug/Src/Registers/Register.o gccDebug/Src/VonNeumannVM.o gccDebug/Src/VM.o  $(Debug_Library_Path) $(Debug_Libraries) -Wl,-rpath,./ -o ../bin/gccDebug/VonNeumannVM

# Compiles file Src/DataBus.cpp for the Debug configuration...
-include gccDebug/Src/DataBus.d
gccDebug/Src/DataBus.o: Src/DataBus.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/DataBus.cpp $(Debug_Include_Path) -o gccDebug/Src/DataBus.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/DataBus.cpp $(Debug_Include_Path) > gccDebug/Src/DataBus.d

# Compiles file Src/Registers/Accumulator.cpp for the Debug configuration...
-include gccDebug/Src/Registers/Accumulator.d
gccDebug/Src/Registers/Accumulator.o: Src/Registers/Accumulator.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/Registers/Accumulator.cpp $(Debug_Include_Path) -o gccDebug/Src/Registers/Accumulator.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/Registers/Accumulator.cpp $(Debug_Include_Path) > gccDebug/Src/Registers/Accumulator.d

# Compiles file Src/ALU.cpp for the Debug configuration...
-include gccDebug/Src/ALU.d
gccDebug/Src/ALU.o: Src/ALU.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/ALU.cpp $(Debug_Include_Path) -o gccDebug/Src/ALU.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/ALU.cpp $(Debug_Include_Path) > gccDebug/Src/ALU.d

# Compiles file Src/ControlUnit.cpp for the Debug configuration...
-include gccDebug/Src/ControlUnit.d
gccDebug/Src/ControlUnit.o: Src/ControlUnit.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/ControlUnit.cpp $(Debug_Include_Path) -o gccDebug/Src/ControlUnit.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/ControlUnit.cpp $(Debug_Include_Path) > gccDebug/Src/ControlUnit.d

# Compiles file Src/CPU.cpp for the Debug configuration...
-include gccDebug/Src/CPU.d
gccDebug/Src/CPU.o: Src/CPU.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/CPU.cpp $(Debug_Include_Path) -o gccDebug/Src/CPU.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/CPU.cpp $(Debug_Include_Path) > gccDebug/Src/CPU.d

# Compiles file Src/Memory.cpp for the Debug configuration...
-include gccDebug/Src/Memory.d
gccDebug/Src/Memory.o: Src/Memory.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/Memory.cpp $(Debug_Include_Path) -o gccDebug/Src/Memory.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/Memory.cpp $(Debug_Include_Path) > gccDebug/Src/Memory.d

# Compiles file Src/Multiplexer.cpp for the Debug configuration...
-include gccDebug/Src/Multiplexer.d
gccDebug/Src/Multiplexer.o: Src/Multiplexer.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/Multiplexer.cpp $(Debug_Include_Path) -o gccDebug/Src/Multiplexer.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/Multiplexer.cpp $(Debug_Include_Path) > gccDebug/Src/Multiplexer.d

# Compiles file Src/OpcodeConverter.cpp for the Debug configuration...
-include gccDebug/Src/OpcodeConverter.d
gccDebug/Src/OpcodeConverter.o: Src/OpcodeConverter.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/OpcodeConverter.cpp $(Debug_Include_Path) -o gccDebug/Src/OpcodeConverter.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/OpcodeConverter.cpp $(Debug_Include_Path) > gccDebug/Src/OpcodeConverter.d

# Compiles file Src/Operation.cpp for the Debug configuration...
-include gccDebug/Src/Operation.d
gccDebug/Src/Operation.o: Src/Operation.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/Operation.cpp $(Debug_Include_Path) -o gccDebug/Src/Operation.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/Operation.cpp $(Debug_Include_Path) > gccDebug/Src/Operation.d

# Compiles file Src/Registers/DataRegister.cpp for the Debug configuration...
-include gccDebug/Src/Registers/DataRegister.d
gccDebug/Src/Registers/DataRegister.o: Src/Registers/DataRegister.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/Registers/DataRegister.cpp $(Debug_Include_Path) -o gccDebug/Src/Registers/DataRegister.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/Registers/DataRegister.cpp $(Debug_Include_Path) > gccDebug/Src/Registers/DataRegister.d

# Compiles file Src/Registers/InstructionRegister.cpp for the Debug configuration...
-include gccDebug/Src/Registers/InstructionRegister.d
gccDebug/Src/Registers/InstructionRegister.o: Src/Registers/InstructionRegister.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/Registers/InstructionRegister.cpp $(Debug_Include_Path) -o gccDebug/Src/Registers/InstructionRegister.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/Registers/InstructionRegister.cpp $(Debug_Include_Path) > gccDebug/Src/Registers/InstructionRegister.d

# Compiles file Src/Registers/OutputRegister.cpp for the Debug configuration...
-include gccDebug/Src/Registers/OutputRegister.d
gccDebug/Src/Registers/OutputRegister.o: Src/Registers/OutputRegister.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/Registers/OutputRegister.cpp $(Debug_Include_Path) -o gccDebug/Src/Registers/OutputRegister.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/Registers/OutputRegister.cpp $(Debug_Include_Path) > gccDebug/Src/Registers/OutputRegister.d

# Compiles file Src/Registers/ProgramCounter.cpp for the Debug configuration...
-include gccDebug/Src/Registers/ProgramCounter.d
gccDebug/Src/Registers/ProgramCounter.o: Src/Registers/ProgramCounter.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/Registers/ProgramCounter.cpp $(Debug_Include_Path) -o gccDebug/Src/Registers/ProgramCounter.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/Registers/ProgramCounter.cpp $(Debug_Include_Path) > gccDebug/Src/Registers/ProgramCounter.d

# Compiles file Src/Registers/Register.cpp for the Debug configuration...
-include gccDebug/Src/Registers/Register.d
gccDebug/Src/Registers/Register.o: Src/Registers/Register.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/Registers/Register.cpp $(Debug_Include_Path) -o gccDebug/Src/Registers/Register.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/Registers/Register.cpp $(Debug_Include_Path) > gccDebug/Src/Registers/Register.d

# Compiles file Src/VonNeumannVM.cpp for the Debug configuration...
-include gccDebug/Src/VonNeumannVM.d
gccDebug/Src/VonNeumannVM.o: Src/VonNeumannVM.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/VonNeumannVM.cpp $(Debug_Include_Path) -o gccDebug/Src/VonNeumannVM.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/VonNeumannVM.cpp $(Debug_Include_Path) > gccDebug/Src/VonNeumannVM.d

# Compiles file Src/VM.cpp for the Debug configuration...
-include gccDebug/Src/VM.d
gccDebug/Src/VM.o: Src/VM.cpp
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -c Src/VM.cpp $(Debug_Include_Path) -o gccDebug/Src/VM.o
	$(CPP_COMPILER) $(Debug_Preprocessor_Definitions) $(Debug_Compiler_Flags) -MM Src/VM.cpp $(Debug_Include_Path) > gccDebug/Src/VM.d

# Builds the Release configuration...
.PHONY: Release
Release: create_folders gccRelease/Src/DataBus.o gccRelease/Src/Registers/Accumulator.o gccRelease/Src/ALU.o gccRelease/Src/ControlUnit.o gccRelease/Src/CPU.o gccRelease/Src/Memory.o gccRelease/Src/Multiplexer.o gccRelease/Src/OpcodeConverter.o gccRelease/Src/Operation.o gccRelease/Src/Registers/DataRegister.o gccRelease/Src/Registers/InstructionRegister.o gccRelease/Src/Registers/OutputRegister.o gccRelease/Src/Registers/ProgramCounter.o gccRelease/Src/Registers/Register.o gccRelease/Src/VonNeumannVM.o gccRelease/Src/VM.o 
	g++ gccRelease/Src/DataBus.o gccRelease/Src/Registers/Accumulator.o gccRelease/Src/ALU.o gccRelease/Src/ControlUnit.o gccRelease/Src/CPU.o gccRelease/Src/Memory.o gccRelease/Src/Multiplexer.o gccRelease/Src/OpcodeConverter.o gccRelease/Src/Operation.o gccRelease/Src/Registers/DataRegister.o gccRelease/Src/Registers/InstructionRegister.o gccRelease/Src/Registers/OutputRegister.o gccRelease/Src/Registers/ProgramCounter.o gccRelease/Src/Registers/Register.o gccRelease/Src/VonNeumannVM.o gccRelease/Src/VM.o  $(Release_Library_Path) $(Release_Libraries) -Wl,-rpath,./ -o ../bin/gccRelease/VonNeumannVM

# Compiles file Src/DataBus.cpp for the Release configuration...
-include gccRelease/Src/DataBus.d
gccRelease/Src/DataBus.o: Src/DataBus.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/DataBus.cpp $(Release_Include_Path) -o gccRelease/Src/DataBus.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/DataBus.cpp $(Release_Include_Path) > gccRelease/Src/DataBus.d

# Compiles file Src/Registers/Accumulator.cpp for the Release configuration...
-include gccRelease/Src/Registers/Accumulator.d
gccRelease/Src/Registers/Accumulator.o: Src/Registers/Accumulator.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/Registers/Accumulator.cpp $(Release_Include_Path) -o gccRelease/Src/Registers/Accumulator.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/Registers/Accumulator.cpp $(Release_Include_Path) > gccRelease/Src/Registers/Accumulator.d

# Compiles file Src/ALU.cpp for the Release configuration...
-include gccRelease/Src/ALU.d
gccRelease/Src/ALU.o: Src/ALU.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/ALU.cpp $(Release_Include_Path) -o gccRelease/Src/ALU.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/ALU.cpp $(Release_Include_Path) > gccRelease/Src/ALU.d

# Compiles file Src/ControlUnit.cpp for the Release configuration...
-include gccRelease/Src/ControlUnit.d
gccRelease/Src/ControlUnit.o: Src/ControlUnit.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/ControlUnit.cpp $(Release_Include_Path) -o gccRelease/Src/ControlUnit.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/ControlUnit.cpp $(Release_Include_Path) > gccRelease/Src/ControlUnit.d

# Compiles file Src/CPU.cpp for the Release configuration...
-include gccRelease/Src/CPU.d
gccRelease/Src/CPU.o: Src/CPU.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/CPU.cpp $(Release_Include_Path) -o gccRelease/Src/CPU.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/CPU.cpp $(Release_Include_Path) > gccRelease/Src/CPU.d

# Compiles file Src/Memory.cpp for the Release configuration...
-include gccRelease/Src/Memory.d
gccRelease/Src/Memory.o: Src/Memory.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/Memory.cpp $(Release_Include_Path) -o gccRelease/Src/Memory.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/Memory.cpp $(Release_Include_Path) > gccRelease/Src/Memory.d

# Compiles file Src/Multiplexer.cpp for the Release configuration...
-include gccRelease/Src/Multiplexer.d
gccRelease/Src/Multiplexer.o: Src/Multiplexer.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/Multiplexer.cpp $(Release_Include_Path) -o gccRelease/Src/Multiplexer.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/Multiplexer.cpp $(Release_Include_Path) > gccRelease/Src/Multiplexer.d

# Compiles file Src/OpcodeConverter.cpp for the Release configuration...
-include gccRelease/Src/OpcodeConverter.d
gccRelease/Src/OpcodeConverter.o: Src/OpcodeConverter.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/OpcodeConverter.cpp $(Release_Include_Path) -o gccRelease/Src/OpcodeConverter.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/OpcodeConverter.cpp $(Release_Include_Path) > gccRelease/Src/OpcodeConverter.d

# Compiles file Src/Operation.cpp for the Release configuration...
-include gccRelease/Src/Operation.d
gccRelease/Src/Operation.o: Src/Operation.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/Operation.cpp $(Release_Include_Path) -o gccRelease/Src/Operation.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/Operation.cpp $(Release_Include_Path) > gccRelease/Src/Operation.d

# Compiles file Src/Registers/DataRegister.cpp for the Release configuration...
-include gccRelease/Src/Registers/DataRegister.d
gccRelease/Src/Registers/DataRegister.o: Src/Registers/DataRegister.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/Registers/DataRegister.cpp $(Release_Include_Path) -o gccRelease/Src/Registers/DataRegister.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/Registers/DataRegister.cpp $(Release_Include_Path) > gccRelease/Src/Registers/DataRegister.d

# Compiles file Src/Registers/InstructionRegister.cpp for the Release configuration...
-include gccRelease/Src/Registers/InstructionRegister.d
gccRelease/Src/Registers/InstructionRegister.o: Src/Registers/InstructionRegister.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/Registers/InstructionRegister.cpp $(Release_Include_Path) -o gccRelease/Src/Registers/InstructionRegister.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/Registers/InstructionRegister.cpp $(Release_Include_Path) > gccRelease/Src/Registers/InstructionRegister.d

# Compiles file Src/Registers/OutputRegister.cpp for the Release configuration...
-include gccRelease/Src/Registers/OutputRegister.d
gccRelease/Src/Registers/OutputRegister.o: Src/Registers/OutputRegister.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/Registers/OutputRegister.cpp $(Release_Include_Path) -o gccRelease/Src/Registers/OutputRegister.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/Registers/OutputRegister.cpp $(Release_Include_Path) > gccRelease/Src/Registers/OutputRegister.d

# Compiles file Src/Registers/ProgramCounter.cpp for the Release configuration...
-include gccRelease/Src/Registers/ProgramCounter.d
gccRelease/Src/Registers/ProgramCounter.o: Src/Registers/ProgramCounter.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/Registers/ProgramCounter.cpp $(Release_Include_Path) -o gccRelease/Src/Registers/ProgramCounter.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/Registers/ProgramCounter.cpp $(Release_Include_Path) > gccRelease/Src/Registers/ProgramCounter.d

# Compiles file Src/Registers/Register.cpp for the Release configuration...
-include gccRelease/Src/Registers/Register.d
gccRelease/Src/Registers/Register.o: Src/Registers/Register.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/Registers/Register.cpp $(Release_Include_Path) -o gccRelease/Src/Registers/Register.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/Registers/Register.cpp $(Release_Include_Path) > gccRelease/Src/Registers/Register.d

# Compiles file Src/VonNeumannVM.cpp for the Release configuration...
-include gccRelease/Src/VonNeumannVM.d
gccRelease/Src/VonNeumannVM.o: Src/VonNeumannVM.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/VonNeumannVM.cpp $(Release_Include_Path) -o gccRelease/Src/VonNeumannVM.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/VonNeumannVM.cpp $(Release_Include_Path) > gccRelease/Src/VonNeumannVM.d

# Compiles file Src/VM.cpp for the Release configuration...
-include gccRelease/Src/VM.d
gccRelease/Src/VM.o: Src/VM.cpp
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -c Src/VM.cpp $(Release_Include_Path) -o gccRelease/Src/VM.o
	$(CPP_COMPILER) $(Release_Preprocessor_Definitions) $(Release_Compiler_Flags) -MM Src/VM.cpp $(Release_Include_Path) > gccRelease/Src/VM.d

# Creates the intermediate and output folders for each configuration...
.PHONY: create_folders
create_folders:
	mkdir -p gccDebug/source
	mkdir -p gccDebug/Src
	mkdir -p gccDebug/Src/Registers
	mkdir -p ../bin/gccDebug
	mkdir -p ../bin/gccDebug/Src
	mkdir -p ../bin/gccDebug/Src/Registers
	mkdir -p gccRelease/source
	mkdir -p gccRelease/Src
	mkdir -p gccRelease/Src/Registers
	mkdir -p ../bin/gccRelease
	mkdir -p ../bin/gccRelease/Src
	mkdir -p ../bin/gccRelease/Src/Registers

# Cleans intermediate and output files (objects, libraries, executables)...
.PHONY: clean
clean:
	rm -f gccDebug/*.o
	rm -f gccDebug/*.d
	rm -f ../bin/gccDebug/*.a
	rm -f ../bin/gccDebug/*.so
	rm -f ../bin/gccDebug/*.dll
	rm -f ../bin/gccDebug/*.exe
	rm -f ../bin/gccDebug/VonNeumannVM
	rm -f gccRelease/*.o
	rm -f gccRelease/*.d
	rm -f ../bin/gccRelease/*.a
	rm -f ../bin/gccRelease/*.so
	rm -f ../bin/gccRelease/*.dll
	rm -f ../bin/gccRelease/*.exe
	rm -f ../bin/gccRelease/VonNeumannVM

