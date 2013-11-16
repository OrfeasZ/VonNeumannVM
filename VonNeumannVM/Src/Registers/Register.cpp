#include "Register.h"

Register::Register()
	: m_EN(false)
{

}

void Register::SetEnable(bool p_Enabled)
{
	m_EN = p_Enabled;
}