#include "Register.h"

Register::Register()
	: m_EN(false)
{
	m_Data = 0;
}

void Register::SetEnable(bool p_Enabled)
{
	m_EN = p_Enabled;
}

bool Register::Write(uint16_t p_Data)
{
	// Check if we're enabled.
	if (!m_EN)
		return false;

	m_Data = p_Data;

	return true;
}


bool Register::Read(uint16_t& p_Data)
{
	// Check if we're enabled.
	//if (!m_EN)
	//	return false;

	p_Data = m_Data;

	return true;
}