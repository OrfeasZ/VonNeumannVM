#include "ProgramCounter.h"

ProgramCounter::ProgramCounter()
{
	m_Data = 0;
}

bool ProgramCounter::Increment()
{
	// Check if we're allowed to write.
	if (!m_EN)
		return false;

	++m_Data;

	// Check if we should reset the counter.
	if (m_Data >= 8192)
		m_Data = 0;

	return true;
}