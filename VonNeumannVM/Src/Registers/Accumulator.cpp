#include "Accumulator.h"

#include "../VM.h"

Accumulator::Accumulator()
{
	m_Data = 0;
}

void Accumulator::Tick()
{
	// Check if we are currently enabled.
	if (!m_EN)
		return;

	// Write our data to Input B of the ALU.
	VM::GetInstance()->GetCPU()->GetALU()->WriteInputB(m_Data);
}