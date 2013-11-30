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
	Operation(Opcode p_Opcode, uint16_t p_Address);
	Operation(uint16_t p_Data);

public:
	Opcode GetOpcode() { return m_Opcode; }
	uint16_t GetAddress() { return m_Address; }
	uint16_t GetData() { return m_Data; }

private:
	Opcode m_Opcode;
	uint16_t m_Address;
	uint16_t m_Data;
};