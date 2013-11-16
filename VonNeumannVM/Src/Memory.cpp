#include "Memory.h"

#include <stdlib.h>

Memory::Memory(unsigned int p_Cells)
	: m_ME_CS(false), m_ME_OE(false), m_ME_RW(false)
{
	if (p_Cells > 8192)
		throw;

	m_MemoryCells = (unsigned short*)malloc(p_Cells);
	m_Size = p_Cells;
}

Memory::~Memory()
{
	free(m_MemoryCells);
}

bool Memory::Read(unsigned int p_Index, unsigned short& p_Data)
{
	// Check if the chip is enabled
	if (!m_ME_CS)
		return false;

	if (p_Index > m_Size - 1)
		return false;

	// Check if output is enabled
	if (m_ME_OE)
		p_Data = m_MemoryCells[p_Index];

	return true;
}

bool Memory::Write(unsigned int p_Index, unsigned short p_Data)
{
	// Check if the chip is enabled
	if (!m_ME_CS)
		return false;

	if (p_Index > m_Size - 1)
		return false;

	m_MemoryCells[p_Index] = p_Data;
	
	return true;
}

void Memory::SetChipSelect(bool p_Enabled)
{
	m_ME_CS = p_Enabled;
}

void Memory::SetOutputEnable(bool p_Enabled)
{
	m_ME_OE	= p_Enabled;
}