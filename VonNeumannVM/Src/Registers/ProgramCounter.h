#pragma once

#include "../stdafx.h"

#include "Register.h"

class ProgramCounter : public Register
{
public:
	ProgramCounter();

public:
	bool Increment();

	bool Write(uint16_t p_Data);
};