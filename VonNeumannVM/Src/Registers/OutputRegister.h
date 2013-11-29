#pragma once

#include "../stdafx.h"

class OutputRegister
{
public:
	OutputRegister();

public:
	void SetOutputEnable(bool p_Enabled);
	bool GetOutputEnable() { return m_OE; }

protected:
	bool m_OE;
};