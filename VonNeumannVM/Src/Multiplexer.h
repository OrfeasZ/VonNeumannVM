#pragma once

#include "stdafx.h"

#include "Interfaces/ITickable.h"

class Multiplexer : public ITickable
{
public:
	Multiplexer();

public:
	void SetSelect(bool p_Select);
	bool GetSelect() { return m_SL; }
	void Tick();

private:
	bool m_SL;
};