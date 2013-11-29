#pragma once

#include "../stdafx.h"

#include "IRegister.h"

class OutputRegister : protected IRegister
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