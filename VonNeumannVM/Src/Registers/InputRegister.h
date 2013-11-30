#pragma once

#include "../stdafx.h"

class InputRegister
{
public:
	InputRegister();

public:
	void SetEnable(bool p_Enabled);
	bool GetEnable() { return m_EN; }

	bool Write(unsigned short p_Data);

protected:
	bool m_EN;

	unsigned short m_Data;
};