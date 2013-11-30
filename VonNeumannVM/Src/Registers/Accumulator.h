#pragma once

#include "../stdafx.h"
#include "../ITickable.h"

#include "OutputRegister.h"

class Accumulator : public OutputRegister
{
public:
	Accumulator();

public:
	void Tick();
};