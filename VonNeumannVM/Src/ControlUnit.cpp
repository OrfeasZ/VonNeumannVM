#include "ControlUnit.h"

ControlUnit::ControlUnit()
	: m_CurrentOpcode(LOAD)
{

}

void ControlUnit::Tick()
{

}

void ControlUnit::WriteOpcode(Opcode p_Opcode)
{
	m_CurrentOpcode = p_Opcode;
}