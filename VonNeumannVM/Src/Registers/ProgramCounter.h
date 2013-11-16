#pragma once

#include "../stdafx.h"

#include "Register.h"

class ProgramCounter : public Register
{
public:
	ProgramCounter();

public:
	bool Read(unsigned short& p_Counter);
	bool Write(unsigned short p_Counter);

private:
	unsigned short m_Counter;
};