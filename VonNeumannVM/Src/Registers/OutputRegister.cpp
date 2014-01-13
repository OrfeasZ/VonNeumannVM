#include "OutputRegister.h"

OutputRegister::OutputRegister()
	: m_OE(false)
{

}

void OutputRegister::SetOutputEnable(bool p_Enabled)
{
	m_OE = p_Enabled;
}