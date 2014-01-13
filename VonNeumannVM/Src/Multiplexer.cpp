#include "Multiplexer.h"

#include "VM.h"

Multiplexer::Multiplexer()
	: m_SL(false)
{

}

void Multiplexer::SetSelect(bool p_Select)
{
	m_SL = p_Select;
}

void Multiplexer::Tick()
{
	uint16_t s_Data;

	if (!m_SL)
	{
		VM::GetInstance()->GetCPU()->GetProgramCounter()->Read(s_Data);
	}
	else
	{
		s_Data = VM::GetInstance()->GetCPU()->GetDataBus()->Read();
		s_Data = Operation(s_Data).GetAddress();
	}

	VM::GetInstance()->GetCPU()->GetAddressRegister()->Write(s_Data);
}