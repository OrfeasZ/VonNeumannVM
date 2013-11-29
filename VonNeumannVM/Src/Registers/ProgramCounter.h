#pragma once

#include "../stdafx.h"

#include "InputRegister.h"

class ProgramCounter : public InputRegister
{
public:
	ProgramCounter();

public:
	bool Read(unsigned short& p_Counter);
	bool Write(unsigned short p_Counter);

private:
	unsigned short m_Counter;
};