#pragma once

#include "stdafx.h"

#include "ITickable.h"
#include "CPU.h"

class ALU
{
public:
	ALU();

public:
	void SetFunction0(bool p_Value);
	void SetFunction1(bool p_Value);
	void SetFunction2(bool p_Value);

	void WriteInputA(unsigned short p_Value);
	void WriteInputB(unsigned short p_Value);

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

	unsigned short m_InputA;
	unsigned short m_InputB;
};