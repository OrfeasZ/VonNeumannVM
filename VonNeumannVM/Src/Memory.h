#pragma once

#include "stdafx.h"

class Memory
{
public:
	Memory(uint16_t p_Cells = 8192);
	~Memory();

public:
	bool Read(uint16_t p_Index, uint16_t& p_Data);
	bool Write(uint16_t p_Index, uint16_t p_Data);

	void SetChipSelect(bool p_Enabled);
	void SetOutputEnable(bool p_Enabled);
	void SetReadWrite(bool p_ReadWrite);

public:
	inline bool GetChipSelect() { return m_ME_CS; }
	inline bool GetOutputEnable() { return m_ME_OE; }
	inline bool GetReadWrite() { return m_ME_RW; }

private:
	uint16_t* m_MemoryCells;
	uint16_t m_Size;

private:
	bool m_ME_CS;
	bool m_ME_OE;
	bool m_ME_RW;

};