#include "Accumulator.h"

#include "../CPU.h"

Accumulator::Accumulator()
{
	m_Data = 0;
}

void Accumulator::Tick()
{
	// Check if we are currently enabled.
	if (!m_EN)
		return;

	// Check if we are allowed to output data.
	if (!m_OE)
		return;

	// Write our data to Input B of the ALU.
	CPU::GetInstance()->GetALU()->WriteInputB(m_Data);

	// TODO: Send data to the internal data bus
}