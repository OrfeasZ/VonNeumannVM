#pragma once

#include "../stdafx.h"

#include "InputRegister.h"
#include "OutputRegister.h"

class DataRegister : public InputRegister, public OutputRegister
{
public:
	DataRegister();

public:
	bool GetDirection() { return m_DR_DI; }
	void SetDirection(bool p_Direction);

private:
	bool m_DR_DI;
};