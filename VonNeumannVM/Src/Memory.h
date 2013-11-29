#pragma once

#include "stdafx.h"

class Memory
{
public:
	Memory(unsigned int p_Cells);
	~Memory();

public:
	bool Read(unsigned int p_Index, unsigned short& p_Data);
	bool Write(unsigned int p_Index, unsigned short p_Data);

	void SetChipSelect(bool p_Enabled);
	void SetOutputEnable(bool p_Enabled);
	void SetReadWrite(bool p_ReadWrite);

public:
	inline bool GetChipSelect() { return m_ME_CS; }
	inline bool GetOutputEnable() { return m_ME_OE; }
	inline bool GetReadWrite() { return m_ME_RW; }

private:
	unsigned short* m_MemoryCells;
	unsigned int m_Size;

private:
	bool m_ME_CS;
	bool m_ME_OE;
	bool m_ME_RW;

};