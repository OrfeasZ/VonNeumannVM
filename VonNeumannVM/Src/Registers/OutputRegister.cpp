#include "OutputRegister.h"

OutputRegister::OutputRegister()
	: m_OE(false)
{

}

void OutputRegister::SetOutputEnable(bool p_Enabled)
{
	m_OE = p_Enabled;
}

bool OutputRegister::Read(uint16_t& p_Data)
{
	// Check if we're allowed to read.
	if (!m_OE)
		return false;

	p_Data = m_Data;

	return true;
}