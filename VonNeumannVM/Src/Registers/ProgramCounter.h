#pragma once

#include "../stdafx.h"

#include "InputRegister.h"

class ProgramCounter : public InputRegister
{
public:
	ProgramCounter();

public:
	bool Increment();
};