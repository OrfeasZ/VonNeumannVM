#include "CPU.h"

#pragma region Singleton

CPU* CPU::m_Instance = NULL;

CPU* CPU::GetInstance()
{
	if (m_Instance == NULL)
		m_Instance = new CPU();

	return m_Instance;
}

#pragma endregion

CPU::CPU()
{

}

Accumulator* CPU::GetAccumulator()
{
	return &m_Accumulator;
}

ALU* CPU::GetALU()
{
	return &m_ALU;
}