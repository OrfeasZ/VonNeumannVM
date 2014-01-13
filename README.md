# VonNeumannVM
A simple Von Neumann Virtual Machine in C++ for my Computer Architecture Course at UOI.

### Authors & Contributors

 - [Orfeas Zafeiris][1]

### Usage
In order to load an assembly file into the VM, simply launch it by specifying the input file as the first parameter.

    VonNeumannVM code.asm
    
After the VM is running, you have several options:

 1. View the data at a specific address in memory. To do that, simply type the decimal representation of the address you wish to view in the console, and press enter.
 2. Modify data at a specific address in memory. To do that, simply type the address you wish to modify and the data you wish to set in the following format `addr = data`, and press enter. For example: `100 = 123`. This will set the data at index `100` to `123`.
 3. Continue to the next tick. To do that, simply press enter.
 

### Notes

 - This VM has only been tested on Windows using the msvc110 compiler.


  [1]: https://github.com/OrfeasZ