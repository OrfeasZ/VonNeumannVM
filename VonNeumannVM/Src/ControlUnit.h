#pragma once

#include "stdafx.h"

#include "ITickable.h"
#include "Operation.h"

class ControlUnit : public ITickable
{
public:
	ControlUnit();

public:
	void Tick();

	void WriteOpcode(Opcode p_Opcode);

private:
	Opcode m_CurrentOpcode;
};