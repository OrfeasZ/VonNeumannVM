#pragma once

#include "stdafx.h"

#include "Registers/Accumulator.h"
#include "Registers/AddressRegister.h"
#include "Registers/DataRegister.h"
#include "Registers/InstructionRegister.h"
#include "Registers/ProgramCounter.h"

#include "ALU.h"

class CPU
{
protected:
	static CPU* m_Instance;

public:
	static CPU* GetInstance();

public:
	CPU();

public:
	Accumulator* GetAccumulator();


private:
	Accumulator m_Accumulator;


};