#pragma once

#include "../stdafx.h"

#include "../Interfaces/IReadable.h"
#include "../Interfaces/IWriteable.h"

class Register : public IReadable, public IWriteable
{
public:
	Register();

public:
	void SetEnable(bool p_Enabled);
	bool GetEnable() { return m_EN; }

	virtual bool Write(uint16_t p_Data);
	virtual bool Read(uint16_t& p_Data);

	virtual bool CanRead() { return m_EN; }
	virtual bool CanWrite() { return m_EN; }

	uint16_t ReadUnsafe() { return m_Data; }

protected:
	bool m_EN;

	uint16_t m_Data;
};