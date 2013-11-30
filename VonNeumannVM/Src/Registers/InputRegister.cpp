#include "InputRegister.h"

InputRegister::InputRegister()
	: m_EN(false)
{

}

void InputRegister::SetEnable(bool p_Enabled)
{
	m_EN = p_Enabled;
}

bool InputRegister::Write(uint16_t p_Data)
{
	// Check if we're allowed to write.
	if (!m_EN)
		return false;

	m_Data = p_Data;

	return true;
}