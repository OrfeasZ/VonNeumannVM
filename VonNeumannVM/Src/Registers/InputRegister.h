#pragma once

#include "../stdafx.h"

class InputRegister
{
public:
	InputRegister();

public:
	void SetEnable(bool p_Enabled);
	bool GetEnable() { return m_EN; }

	bool Write(uint16_t p_Data);

protected:
	bool m_EN;

	uint16_t m_Data;
};