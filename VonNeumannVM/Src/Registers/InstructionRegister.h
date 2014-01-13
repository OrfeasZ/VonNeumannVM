#pragma once

#include "../stdafx.h"
#include "../Interfaces/ITickable.h"

#include "Register.h"

class InstructionRegister : public Register, public ITickable
{
public:
	void Tick();

	bool Write(uint16_t p_Data);
};