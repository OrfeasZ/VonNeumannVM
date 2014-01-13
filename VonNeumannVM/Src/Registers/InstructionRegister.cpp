#include "InstructionRegister.h"

#include "../VM.h"
#include "../Operation.h"

void InstructionRegister::Tick()
{
	// Check if we are enabled.
	if (!m_EN)
		return;

	VM::GetInstance()->GetCPU()->GetControlUnit()->WriteOpcode((Opcode) m_Data);
}

bool InstructionRegister::Write(uint16_t p_Data)
{
	if (!Register::Write(p_Data))
		return false;

	m_Data = Operation(m_Data).GetOpcode();

	return true;
}