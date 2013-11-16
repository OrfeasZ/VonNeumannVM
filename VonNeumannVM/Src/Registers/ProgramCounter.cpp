#include "ProgramCounter.h"

ProgramCounter::ProgramCounter()
	: m_Counter(0)
{

}

bool ProgramCounter::Read(unsigned short& p_Counter)
{
	// Check if we should be allowed to read in this cycle
	if (m_EN)
		return false;

	p_Counter = m_Counter;

	return true;
}

bool ProgramCounter::Write(unsigned short p_Counter)
{
	// Check if we should be allowed to write in this cycle
	if (!m_EN)
		return false;

	m_Counter = p_Counter;

	return true;
}