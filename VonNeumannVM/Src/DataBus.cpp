#include "DataBus.h"

#include "Memory.h"

#include "Registers/OutputRegister.h"

DataBus::DataBus()
{

}

DataBus::~DataBus()
{
	m_Writeables.clear();
	m_Readables.clear();
}

uint16_t DataBus::Read()
{
	uint16_t s_Data = 0;

	for (auto it = m_Readables.begin(); it != m_Readables.end(); ++it)
	{
		if (!(*it)->CanRead())
			continue;

		(*it)->Read(s_Data);
	}

	for (auto it = m_DataRegisters.begin(); it != m_DataRegisters.end(); ++it)
	{
		if (it->first->GetDirection() != it->second)
			continue;

		if (!it->first->CanRead())
			continue;

		it->first->Read(s_Data);
	}

	return s_Data;
}

void DataBus::Tick()
{
	uint16_t s_Data = Read();

	for (auto it = m_Writeables.begin(); it != m_Writeables.end(); ++it)
	{
		if (!(*it)->CanWrite())
			continue;

		(*it)->Write(s_Data);
	}

	for (auto it = m_DataRegisters.begin(); it != m_DataRegisters.end(); ++it)
	{
		if (it->first->GetDirection() == it->second)
			continue;

		if (!it->first->CanWrite())
			continue;

		it->first->Write(s_Data);
	}
}

void DataBus::ConnectReadable(IReadable* p_Readable)
{
	m_Readables.push_back(p_Readable);
}

void DataBus::ConnectWriteable(IWriteable* p_Readable)
{
	m_Writeables.push_back(p_Readable);
}

void DataBus::ConnectDataRegister(DataRegister* p_Register, bool p_Direction)
{
	m_DataRegisters[p_Register] = p_Direction;
}