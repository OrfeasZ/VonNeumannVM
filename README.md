# VonNeumannVM
A simple Von Neumann Virtual Machine in C++ for my Computer Architecture Course at UOI.

### Authors & Contributors

 - [Orfeas Zafeiris][1]

### Usage
In order to load an assembly file into the VM, simply launch it by specifying the input file as the first parameter.

    VonNeumannVM code.asm
    
After the VM is running, you have several options:

 - View the data at a specific address in memory. To do that, simply type the decimal representation of the address you wish to view in the console, and press enter.
 - Modify data at a specific address in memory. To do that, simply type the address you wish to modify and the data you wish to set in the following format `addr = data`, and press enter. For example: `100 = 123`. This will set the data at index `100` to `123`.
 - Continue to the next tick. To do that, simply press enter.
 
### Supported Operations

 - `load [addr]` - Load data from `[addr]` to the AC.
 - `store [addr]` - Store data from AC to `[addr]`.
 - `add [addr]` - Load data from `[addr]` to the DR, add data to AC, and write result to AC. 
 - `and [addr]` - Load data from `[addr]` to the DR, AND data with AC, and write result to AC. 
 - `jump [addr]` - Sets the PC to `[addr]`.
 - `jumpz [addr]` - If the data in the AC is Zero, sets the PC to `[addr]`.
 - `comp` - Complements the data in the AC.
 - `rshift` - Right shifts the data in the AC by 1.

### Glossary

 - `AC` - Accumulator
 - `ALU` - Arithmetic Logic Unit
 - `AR` - Address Register
 - `CPU` - Central Processing Unit
 - `DR` - Data Register
 - `IR` - Instruction Register
 - `PC` - Program Counter
 - `MEM` - Main Memory
 - `MX` - Multiplexer

### Example Program

    load 100h
    add 101h
    store 102h
    
This little program will load the data from address 0x0100 of the Main Memory to the Accumulator, it will add to it the data on address 0x0101, and then save the result to address 0x0102. 
 
### License

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 
### Notes

 - This VM has only been tested on Windows using the msvc110 compiler.


  [1]: https://github.com/OrfeasZ