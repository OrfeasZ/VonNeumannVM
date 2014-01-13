#include "OpcodeConverter.h"

#include <sstream>
#include <iostream>
#include <fstream>

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

Operation OpcodeConverter::Convert(const std::string& p_Data)
{
	std::vector<std::string> s_Elements;
	std::stringstream s_Stream(p_Data);
	std::string s_Item;
	while (std::getline(s_Stream, s_Item, ' '))
		s_Elements.push_back(s_Item);

	Opcode s_Opcode = (Opcode)0;
	uint16_t s_Data = 0;

	if (s_Elements.size() == 0)
		return Operation(s_Opcode, s_Data);

	s_Opcode = OpcodeConvert(s_Elements[0]);

	if (s_Elements.size() == 1)
		return Operation(s_Opcode, s_Data);

	std::stringstream s_TempStream;

	// Hex value
	if (*s_Elements[1].rbegin() == 'h')
	{
		s_Elements[1] = s_Elements[1].substr(0, s_Elements[1].size() - 1); unsigned int x;
		
		s_TempStream << std::hex << s_Elements[1];
		s_TempStream >> s_Data;
	}
	else
	{
		s_TempStream >> s_Data;
	}

	return Operation(s_Opcode, s_Data);
}

std::string OpcodeConverter::Convert(Operation s_Operation)
{
	std::string s_Final = OpcodeConvert(s_Operation.GetOpcode());

	if (s_Operation.GetOpcode() == COMP || s_Operation.GetOpcode() == RSHIFT)
		return s_Final;

	char s_HexData[128];
	sprintf(s_HexData, "%s %04Xh", s_Final.c_str(), s_Operation.GetAddress());

	return s_HexData;
}

Opcode OpcodeConverter::OpcodeConvert(const std::string& p_Data)
{
	if (p_Data == "load")
		return LOAD;

	if (p_Data == "store")
		return STORE;

	if (p_Data == "add")
		return ADD;

	if (p_Data == "and")
		return AND;

	if (p_Data == "jump")
		return JUMP;

	if (p_Data == "jumpz")
		return JUMPZ;

	if (p_Data == "comp")
		return COMP;

	return RSHIFT;
}

std::string OpcodeConverter::OpcodeConvert(Opcode p_Data)
{
	switch (p_Data)
	{
	case LOAD:
		return "load";
	case STORE:
		return "store";
	case ADD:
		return "add";
	case AND:
		return "and";
	case JUMP:
		return "jump";
	case JUMPZ:
		return "jumpz";
	case COMP:
		return "comp";
	default:
		return "rshift";
	}
}

std::vector<Operation> OpcodeConverter::ConvertFile(const std::string& p_File)
{
	std::ifstream s_File(p_File);
	std::string s_Line;

	std::vector<Operation> s_Operations;

	while (std::getline(s_File, s_Line))
	{
		s_Operations.push_back(Convert(s_Line));
	}

	return s_Operations;
}