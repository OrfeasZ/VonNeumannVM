#pragma once

#include "stdafx.h"

enum Opcode
{
	LOAD,
	STORE,
	ADD,
	AND,
	JUMP,
	JUMPZ,
	COMP,
	RSHIFT
};

class Operation
{
public:
	Operation(Opcode p_Opcode, unsigned short p_Address);
	Operation(unsigned short p_Data);

public:
	Opcode GetOpcode() { return m_Opcode; }
	unsigned short GetAddress() { return m_Address; }
	unsigned short GetData() { return m_Data; }

private:
	Opcode m_Opcode;
	unsigned short m_Address;
	unsigned short m_Data;
};