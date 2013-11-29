#include "DataRegister.h"

DataRegister::DataRegister()
	: m_DR_DI(false)
{
	
}

void DataRegister::SetDirection(bool p_Direction)
{
	m_DR_DI = p_Direction;
}