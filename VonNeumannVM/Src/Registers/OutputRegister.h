#pragma once

#include "../stdafx.h"

#include "InputRegister.h"

class OutputRegister : public InputRegister
{
public:
	OutputRegister();

public:
	void SetOutputEnable(bool p_Enabled);
	bool GetOutputEnable() { return m_OE; }

	bool Read(unsigned short& p_Data);

protected:
	bool m_OE;
};