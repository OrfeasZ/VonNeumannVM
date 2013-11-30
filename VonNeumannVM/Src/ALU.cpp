#include "ALU.h"

#include "CPU.h"

ALU::ALU()
	: m_F0(false), m_F1(false), m_F2(false),
	  m_InputA(0), m_InputB(0)
{
	
}

void ALU::SetFunction0(bool p_Value)
{
	m_F0 = p_Value;
}

void ALU::SetFunction1(bool p_Value)
{
	m_F1 = p_Value;
}

void ALU::SetFunction2(bool p_Value)
{
	m_F2 = p_Value;
}

void ALU::WriteInputA(uint16_t p_Value)
{
	m_InputA = p_Value;
}

void ALU::WriteInputB(uint16_t p_Value)
{
	m_InputB = p_Value;
}

void ALU::Tick()
{
	ALU::Operation s_Operation = (ALU::Operation)((m_F0 ? 1 : 0) << 0 | (m_F1 ? 1 : 0) << 1 | (m_F2 ? 1 : 0) << 2);

	uint16_t s_Result = m_InputA;

	switch (s_Operation)
	{
	case Add:
		s_Result += m_InputB;
		break;
	case And:
		s_Result &= m_InputB;
		break;
	case Complement:
		CPU::GetInstance()->GetAccumulator()->Read(s_Result);
		s_Result = ~s_Result;
		break;
	case RightShift:
		CPU::GetInstance()->GetAccumulator()->Read(s_Result);
		s_Result >>= 1;
		break;
	case NoOp:
	default:
		// Simply transfer data to the Accumulator.
		break;
	}

	CPU::GetInstance()->GetAccumulator()->Write(s_Result);
}