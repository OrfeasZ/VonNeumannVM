#pragma once

#include "stdafx.h"

#include "Interfaces/ITickable.h"
#include "Interfaces/IWriteable.h"

class ALU : public IWriteable
{
public:
	ALU();

public:
	void SetFunction0(bool p_Value);
	void SetFunction1(bool p_Value);
	void SetFunction2(bool p_Value);

	bool GetFunction0() { return m_F0; }
	bool GetFunction1() { return m_F1; }
	bool GetFunction2() { return m_F2; }

	bool Write(uint16_t p_Value);
	void WriteInputB(uint16_t p_Value);

	uint16_t GetA() { return m_InputA; }
	uint16_t GetB() { return m_InputB; }

	bool CanWrite();

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