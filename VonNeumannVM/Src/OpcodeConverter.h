#pragma once

#include "stdafx.h"
#include "Operation.h"

#include <string>
#include <vector>

class OpcodeConverter
{
public:
	static Operation Convert(const std::string& p_Data);
	static std::vector<Operation> ConvertFile(const std::string& p_File);
	static std::string Convert(Operation s_Operation);
	static Opcode OpcodeConvert(const std::string& p_Data);
	static std::string OpcodeConvert(Opcode p_Data);
};