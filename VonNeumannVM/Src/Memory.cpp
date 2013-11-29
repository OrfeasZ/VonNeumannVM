#include "Memory.h"

#include <stdlib.h>

Memory::Memory(unsigned int p_Cells)
	: m_ME_CS(false), m_ME_OE(false), m_ME_RW(false)
{
	// We currently don't support a memory with a capacity of over 16kb
	if (p_Cells > 8192)
		throw;

	// Allocate the required memory
	m_MemoryCells = (unsigned short*)malloc(p_Cells);
	m_Size = p_Cells;
}

Memory::~Memory()
{
	// Free the allocated memory
	free(m_MemoryCells);
}

bool Memory::Read(unsigned int p_Index, unsigned short& p_Data)
{
	// Check if the chip is enabled
	if (!m_ME_CS)
		return false;

	// Check if we are in read mode
	if (m_ME_RW)
		return false;

	// Check if we're trying to read inside the bounds of the memory
	if (p_Index > m_Size - 1)
		return false;

	// Check if output is enabled
	if (!m_ME_OE)
		return false;
	
	p_Data = m_MemoryCells[p_Index];

	return true;
}

bool Memory::Write(unsigned int p_Index, unsigned short p_Data)
{
	// Check if the chip is enabled
	if (!m_ME_CS)
		return false;

	// Check if we are in write mode
	if (!m_ME_RW)
		return false;

	// Check if we're trying to write inside the bounds of the memory
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

void Memory::SetReadWrite(bool p_ReadWrite)
{
	m_ME_RW	= p_ReadWrite;
}