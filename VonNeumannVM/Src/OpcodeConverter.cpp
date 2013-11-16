#include "OpcodeConverter.h"

/**
 * Available Opcodes:
 * ------------------
 * LOAD [ADDR] - Load data from [ADDR] to the AC.
 * STORE [ADDR] - Store data from AC to [ADDR].
 * ADD [ADDR] - Load data from [ADDR] to the DR, add data to AC, and write result to AC. 
 * AND [ADDR] - Load data from [ADDR] to the DR, AND data with AC, and write result to AC. 
 * JUMP [ADDR] - Sets the PC to [ADDR].
 * JUMPZ [ADDR] - If the data in the AC is Zero, sets the PC to [ADDR].
 * COMP - Complements the data in the AC.
 * RSHIFT - Right shifts the data in the AC by 1.
 *
 * Notes:
 * ------
 * Each operation is 16 bits in length.
 * First 3 bits are the opcode, rest are the address param.
 *
 * Binary Opcodes:
 * ---------------
 * LOAD = 000
 * STORE = 001
 * ADD = 010
 * AND = 011
 * JUMP = 100
 * JUMPZ = 101
 * COMP = 110
 * RSHIFT = 111
 */
