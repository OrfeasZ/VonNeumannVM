#pragma once

#include <list>
#include <map>

#include "stdafx.h"
#include "Interfaces/ITickable.h"
#include "Interfaces/IReadable.h"
#include "Interfaces/IWriteable.h"

#include "Registers/DataRegister.h"

class Memory;

class DataBus : public ITickable
{
public:
	DataBus();
	~DataBus();

public:
	void Tick();

	uint16_t Read();

	void ConnectReadable(IReadable* p_Readable);
	void ConnectWriteable(IWriteable* p_Writeable);
	void ConnectDataRegister(DataRegister* p_Register, bool p_Direction);

private:
	std::list<IReadable*> m_Readables;
	std::list<IWriteable*> m_Writeables;
	std::map<DataRegister*, bool> m_DataRegisters;

};