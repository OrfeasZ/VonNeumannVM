#include "Operation.h"

Operation::Operation(Opcode p_Opcode, unsigned short p_Address)
	: m_Opcode(p_Opcode), m_Address(p_Address)
{
	m_Data = (unsigned short)m_Opcode;

	m_Data <<= 13;
	m_Data |= m_Address;
}

Operation::Operation(unsigned short p_Data)
	: m_Data(p_Data)
{
	m_Opcode = (Opcode)(m_Data >> 13);
	m_Address = m_Data & 0x1FFF;
}