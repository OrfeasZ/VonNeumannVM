#pragma once

#include "../stdafx.h"
#include "../Interfaces/ITickable.h"

#include "OutputRegister.h"

class Accumulator : public OutputRegister
{
public:
	Accumulator();

public:
	void Tick();
};