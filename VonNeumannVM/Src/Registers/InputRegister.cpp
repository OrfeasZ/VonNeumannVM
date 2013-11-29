#include "InputRegister.h"

InputRegister::InputRegister()
	: m_EN(false)
{

}

void InputRegister::SetEnable(bool p_Enabled)
{
	m_EN = p_Enabled;
}