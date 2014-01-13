#pragma once

#include "stdafx.h"

#include "CPU.h"
#include "Memory.h"

class VM
{
private:
	static VM* m_Instance;

public:
	static VM* GetInstance();

public:
	VM();

public:
	CPU* GetCPU() { return &m_CPU; }
	Memory* GetMemory() { return &m_Memory; }
	DataBus* GetDataBus() { return &m_DataBus; }
	DataBus* GetAddressBus() { return &m_AddressBus; }

	void Clear();
	void Start(const std::string& p_Input = "");
	void PrintState();
	bool ReadInput();

private:
	CPU m_CPU;
	Memory m_Memory;
	DataBus m_DataBus;
	DataBus m_AddressBus;
	uint32_t m_TickCount;
};