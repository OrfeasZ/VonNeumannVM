#include "ProgramCounter.h"

#include "../Operation.h"

ProgramCounter::ProgramCounter()
{
	m_Data = 0;
}

bool ProgramCounter::Increment()
{
	++m_Data;

	// Check if we should reset the counter.
	if (m_Data >= 8192)
		m_Data = 0;

	return true;
}

bool ProgramCounter::Write(uint16_t p_Data)
{
	if (!Register::Write(p_Data))
		return false;

	m_Data = Operation(m_Data).GetAddress();

	return true;
}