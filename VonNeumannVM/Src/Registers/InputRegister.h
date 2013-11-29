#pragma once

#include "../stdafx.h"

class InputRegister
{
public:
	InputRegister();

public:
	void SetEnable(bool p_Enabled);
	bool GetEnable() { return m_EN; }

protected:
	bool m_EN;
};