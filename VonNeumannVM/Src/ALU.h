#pragma once

#include "stdafx.h"

#include "ITickable.h"

class ALU
{
public:
	ALU();

public:
	void SetFunction0(bool p_Value);
	void SetFunction1(bool p_Value);
	void SetFunction2(bool p_Value);

	void WriteInputA(uint16_t p_Value);
	void WriteInputB(uint16_t p_Value);

	void Tick();

private:
	enum Operation
	{
		NoOp,
		Add,
		And,
		Complement,
		RightShift
	};

private:
	bool m_F0;
	bool m_F1;
	bool m_F2;

	uint16_t m_InputA;
	uint16_t m_InputB;
};