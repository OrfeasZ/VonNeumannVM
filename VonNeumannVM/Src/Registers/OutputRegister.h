#pragma once

#include "../stdafx.h"

#include "Register.h"

class OutputRegister : public Register
{
public:
	OutputRegister();

public:
	void SetOutputEnable(bool p_Enabled);
	bool GetOutputEnable() { return m_OE; }

	bool CanRead() { return m_OE; }

protected:
	bool m_OE;
};