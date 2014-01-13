#pragma once

#include "stdafx.h"

#include "Interfaces/IReadable.h"
#include "Interfaces/IWriteable.h"

class Memory : public IReadable, public IWriteable
{
public:
	Memory(uint16_t p_Cells = 8192);
	~Memory();

public:
	class AddressHolder : public IWriteable
	{
	public:
		bool Write(uint16_t p_Data) { m_Address = p_Data; return true; }
		bool CanWrite() { return true; }
		uint16_t GetAddress() { return m_Address; }

	private:
		uint16_t m_Address;
	};

public:
	bool Read(uint16_t p_Index, uint16_t& p_Data);
	bool Write(uint16_t p_Index, uint16_t p_Data);

	bool Read(uint16_t& p_Data);
	bool Write(uint16_t p_Data);

	void SetChipSelect(bool p_Enabled);
	void SetOutputEnable(bool p_Enabled);
	void SetReadWrite(bool p_ReadWrite);

	void ReadUnsafe(uint16_t p_Index, uint16_t& p_Data);
	void WriteUnsafe(uint16_t p_Index, uint16_t p_Data);

public:
	bool GetChipSelect() { return m_ME_CS; }
	bool GetOutputEnable() { return m_ME_OE; }
	bool GetReadWrite() { return m_ME_RW; }

	bool CanRead() { return !m_ME_RW && m_ME_CS && m_ME_OE; }
	bool CanWrite() { return m_ME_RW && m_ME_CS; }

	AddressHolder* GetAddressHolder() { return &m_AddressHolder; }

private:
	uint16_t* m_MemoryCells;
	uint16_t m_Size;
	AddressHolder m_AddressHolder;

private:
	bool m_ME_CS;
	bool m_ME_OE;
	bool m_ME_RW;

};