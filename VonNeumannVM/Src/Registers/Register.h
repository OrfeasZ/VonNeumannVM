#pragma once

#include "../stdafx.h"

#include "IRegister.h"

class Register : public IRegister
{
public:
	Register();

public:
	void SetEnable(bool p_Enabled);
	bool GetEnable() { return m_EN; }

protected:
	bool m_EN;
};