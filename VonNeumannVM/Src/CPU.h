#pragma once

#include "stdafx.h"

#include "Registers/Accumulator.h"
#include "Registers/AddressRegister.h"
#include "Registers/DataRegister.h"
#include "Registers/InstructionRegister.h"
#include "Registers/ProgramCounter.h"

#include "ALU.h"
#include "ControlUnit.h"
#include "Multiplexer.h"
#include "DataBus.h"

class CPU
{
public:
	CPU();

public:
	enum State
	{
		Fetch,
		Decode,
		DataFetch,
		Execute,
		Store,
		MaxStates
	};

public:
	void Process();

public:
	Accumulator* GetAccumulator() { return &m_Accumulator; }
	AddressRegister* GetAddressRegister() { return &m_AddressRegister; }
	ALU* GetALU() { return &m_ALU; }
	ControlUnit* GetControlUnit() { return &m_ControlUnit; }
	DataRegister* GetDataRegister() { return &m_DataRegister; }
	InstructionRegister* GetInstructionRegister() { return &m_InstructionRegister; }
	Multiplexer* GetMultiplexer() { return &m_Multiplexer; }
	ProgramCounter* GetProgramCounter() { return &m_ProgramCounter; }
	DataBus* GetDataBus() { return &m_DataBus; }

	State GetCurrentState() { return m_CurrentState; }

private:
	Accumulator m_Accumulator;
	AddressRegister m_AddressRegister;
	ALU m_ALU;
	ControlUnit m_ControlUnit;
	DataRegister m_DataRegister;
	InstructionRegister m_InstructionRegister;
	Multiplexer m_Multiplexer;
	ProgramCounter m_ProgramCounter;
	DataBus m_DataBus;

	State m_CurrentState;

};