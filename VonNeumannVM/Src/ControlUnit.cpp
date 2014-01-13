#include "ControlUnit.h"

#include "VM.h"

ControlUnit::ControlUnit()
	: m_CurrentOpcode(LOAD), m_CurrentState(0)
{

}

void ControlUnit::Tick()
{
	switch (m_CurrentState)
	{
	case 0:
		TriggerFetch();
		break;
	case 1:
		TriggerPreExecute();
		break;
	case 2:
		TriggerPostExecute();
		break;
	default:
		break;
	}
}

void ControlUnit::WriteOpcode(Opcode p_Opcode)
{
	m_CurrentOpcode = p_Opcode;
}

void ControlUnit::TriggerFetch()
{
	CPU* s_CPU = VM::GetInstance()->GetCPU();
	Memory* s_Memory = VM::GetInstance()->GetMemory();

	s_Memory->SetReadWrite(false);
	s_Memory->SetChipSelect(true);
	s_Memory->SetOutputEnable(true);

	s_CPU->GetDataRegister()->SetDirection(false);
	s_CPU->GetDataRegister()->SetEnable(true);
	s_CPU->GetDataRegister()->SetOutputEnable(true);

	s_CPU->GetInstructionRegister()->SetEnable(true);

	s_CPU->GetProgramCounter()->SetEnable(false);

	s_CPU->GetMultiplexer()->SetSelect(false);

	s_CPU->GetAddressRegister()->SetEnable(true);
	s_CPU->GetAddressRegister()->SetOutputEnable(true);

	s_CPU->GetAccumulator()->SetEnable(false);
	s_CPU->GetAccumulator()->SetOutputEnable(false);

	s_CPU->GetALU()->SetFunction0(false);
	s_CPU->GetALU()->SetFunction1(false);
	s_CPU->GetALU()->SetFunction2(false);

	s_CPU->GetMultiplexer()->Tick();

	VM::GetInstance()->GetAddressBus()->Tick();
	VM::GetInstance()->GetDataBus()->Tick();

	s_CPU->GetDataBus()->Tick();
	s_CPU->GetInstructionRegister()->Tick();

	s_CPU->GetProgramCounter()->Increment();

	++m_CurrentState;
}

void ControlUnit::TriggerPreExecute()
{
	CPU* s_CPU = VM::GetInstance()->GetCPU();
	Memory* s_Memory = VM::GetInstance()->GetMemory();

	s_Memory->SetReadWrite(false);
	s_Memory->SetChipSelect(true);
	s_Memory->SetOutputEnable(false);

	s_CPU->GetDataRegister()->SetDirection(false);
	s_CPU->GetDataRegister()->SetEnable(true);
	s_CPU->GetDataRegister()->SetOutputEnable(true);

	s_CPU->GetInstructionRegister()->SetEnable(false);

	s_CPU->GetProgramCounter()->SetEnable(false);

	s_CPU->GetMultiplexer()->SetSelect(true);

	s_CPU->GetAddressRegister()->SetEnable(true);
	s_CPU->GetAddressRegister()->SetOutputEnable(true);

	s_CPU->GetAccumulator()->SetEnable(false);
	s_CPU->GetAccumulator()->SetOutputEnable(false);

	s_CPU->GetALU()->SetFunction0(false);
	s_CPU->GetALU()->SetFunction1(false);
	s_CPU->GetALU()->SetFunction2(false);

	s_CPU->GetMultiplexer()->Tick();

	VM::GetInstance()->GetAddressBus()->Tick();

	++m_CurrentState;
}

void ControlUnit::TriggerPostExecute()
{
	uint16_t s_Data;
	VM::GetInstance()->GetCPU()->GetInstructionRegister()->Read(s_Data);
	
	switch ((Opcode) s_Data)
	{
	case LOAD:
		TriggerLoadPostExecute();
		break;
	case STORE:
		TriggerStorePostExecute();
		break;
	case ADD:
		TriggerAddPostExecute();
		break;
	case AND:
		TriggerAndPostExecute();
		break;
	case JUMP:
		TriggerJumpPostExecute();
		break;
	case JUMPZ:
		TriggerJumpzPostExecute();
		break;
	case COMP:
		TriggerCompPostExecute();
		break;
	case RSHIFT:
		TriggerRShiftPostExecute();
		break;
	}
}

void ControlUnit::TriggerLoadPostExecute()
{
	CPU* s_CPU = VM::GetInstance()->GetCPU();
	Memory* s_Memory = VM::GetInstance()->GetMemory();

	s_Memory->SetReadWrite(false);
	s_Memory->SetChipSelect(true);
	s_Memory->SetOutputEnable(true);

	s_CPU->GetDataRegister()->SetDirection(false);
	s_CPU->GetDataRegister()->SetEnable(true);
	s_CPU->GetDataRegister()->SetOutputEnable(true);

	s_CPU->GetInstructionRegister()->SetEnable(false);

	s_CPU->GetProgramCounter()->SetEnable(false);

	s_CPU->GetMultiplexer()->SetSelect(false);

	s_CPU->GetAddressRegister()->SetEnable(false);
	s_CPU->GetAddressRegister()->SetOutputEnable(false);

	s_CPU->GetAccumulator()->SetEnable(true);
	s_CPU->GetAccumulator()->SetOutputEnable(false);

	s_CPU->GetALU()->SetFunction0(false);
	s_CPU->GetALU()->SetFunction1(false);
	s_CPU->GetALU()->SetFunction2(false);

	VM::GetInstance()->GetDataBus()->Tick();

	s_CPU->GetDataBus()->Tick();
	s_CPU->GetALU()->Tick();

	m_CurrentState = 0;
}

void ControlUnit::TriggerAddPostExecute()
{
	CPU* s_CPU = VM::GetInstance()->GetCPU();
	Memory* s_Memory = VM::GetInstance()->GetMemory();

	s_Memory->SetReadWrite(false);
	s_Memory->SetChipSelect(true);
	s_Memory->SetOutputEnable(true);

	s_CPU->GetDataRegister()->SetDirection(false);
	s_CPU->GetDataRegister()->SetEnable(true);
	s_CPU->GetDataRegister()->SetOutputEnable(true);

	s_CPU->GetInstructionRegister()->SetEnable(false);

	s_CPU->GetProgramCounter()->SetEnable(false);

	s_CPU->GetMultiplexer()->SetSelect(false);

	s_CPU->GetAddressRegister()->SetEnable(false);
	s_CPU->GetAddressRegister()->SetOutputEnable(false);

	s_CPU->GetAccumulator()->SetEnable(true);
	s_CPU->GetAccumulator()->SetOutputEnable(false);

	s_CPU->GetALU()->SetFunction0(true);
	s_CPU->GetALU()->SetFunction1(false);
	s_CPU->GetALU()->SetFunction2(false);

	s_CPU->GetAccumulator()->Tick();

	VM::GetInstance()->GetDataBus()->Tick();

	s_CPU->GetDataBus()->Tick();
	s_CPU->GetALU()->Tick();

	m_CurrentState = 0;
}

void ControlUnit::TriggerStorePostExecute()
{
	CPU* s_CPU = VM::GetInstance()->GetCPU();
	Memory* s_Memory = VM::GetInstance()->GetMemory();

	s_Memory->SetReadWrite(true);
	s_Memory->SetChipSelect(true);
	s_Memory->SetOutputEnable(false);

	s_CPU->GetDataRegister()->SetDirection(true);
	s_CPU->GetDataRegister()->SetEnable(true);
	s_CPU->GetDataRegister()->SetOutputEnable(true);

	s_CPU->GetInstructionRegister()->SetEnable(false);

	s_CPU->GetProgramCounter()->SetEnable(false);

	s_CPU->GetMultiplexer()->SetSelect(false);

	s_CPU->GetAddressRegister()->SetEnable(false);
	s_CPU->GetAddressRegister()->SetOutputEnable(false);

	s_CPU->GetAccumulator()->SetEnable(true);
	s_CPU->GetAccumulator()->SetOutputEnable(true);

	s_CPU->GetALU()->SetFunction0(false);
	s_CPU->GetALU()->SetFunction1(false);
	s_CPU->GetALU()->SetFunction2(false);

	s_CPU->GetDataBus()->Tick();

	VM::GetInstance()->GetDataBus()->Tick();

	m_CurrentState = 0;
}

void ControlUnit::TriggerAndPostExecute()
{
	CPU* s_CPU = VM::GetInstance()->GetCPU();
	Memory* s_Memory = VM::GetInstance()->GetMemory();

	s_Memory->SetReadWrite(false);
	s_Memory->SetChipSelect(true);
	s_Memory->SetOutputEnable(true);

	s_CPU->GetDataRegister()->SetDirection(false);
	s_CPU->GetDataRegister()->SetEnable(true);
	s_CPU->GetDataRegister()->SetOutputEnable(true);

	s_CPU->GetInstructionRegister()->SetEnable(false);

	s_CPU->GetProgramCounter()->SetEnable(false);

	s_CPU->GetMultiplexer()->SetSelect(false);

	s_CPU->GetAddressRegister()->SetEnable(false);
	s_CPU->GetAddressRegister()->SetOutputEnable(false);

	s_CPU->GetAccumulator()->SetEnable(true);
	s_CPU->GetAccumulator()->SetOutputEnable(false);

	s_CPU->GetALU()->SetFunction0(false);
	s_CPU->GetALU()->SetFunction1(true);
	s_CPU->GetALU()->SetFunction2(false);

	s_CPU->GetAccumulator()->Tick();

	VM::GetInstance()->GetDataBus()->Tick();

	s_CPU->GetDataBus()->Tick();
	s_CPU->GetALU()->Tick();

	m_CurrentState = 0;
}

void ControlUnit::TriggerJumpPostExecute()
{
	CPU* s_CPU = VM::GetInstance()->GetCPU();
	Memory* s_Memory = VM::GetInstance()->GetMemory();

	s_Memory->SetReadWrite(false);
	s_Memory->SetChipSelect(true);
	s_Memory->SetOutputEnable(true);

	s_CPU->GetDataRegister()->SetDirection(false);
	s_CPU->GetDataRegister()->SetEnable(true);
	s_CPU->GetDataRegister()->SetOutputEnable(true);

	s_CPU->GetInstructionRegister()->SetEnable(false);

	s_CPU->GetProgramCounter()->SetEnable(true);

	s_CPU->GetMultiplexer()->SetSelect(false);

	s_CPU->GetAddressRegister()->SetEnable(false);
	s_CPU->GetAddressRegister()->SetOutputEnable(false);

	s_CPU->GetAccumulator()->SetEnable(false);
	s_CPU->GetAccumulator()->SetOutputEnable(false);

	s_CPU->GetALU()->SetFunction0(false);
	s_CPU->GetALU()->SetFunction1(false);
	s_CPU->GetALU()->SetFunction2(false);

	s_CPU->GetDataBus()->Tick();

	m_CurrentState = 0;
}

void ControlUnit::TriggerJumpzPostExecute()
{
	CPU* s_CPU = VM::GetInstance()->GetCPU();
	Memory* s_Memory = VM::GetInstance()->GetMemory();

	s_Memory->SetReadWrite(false);
	s_Memory->SetChipSelect(true);
	s_Memory->SetOutputEnable(true);

	s_CPU->GetDataRegister()->SetDirection(false);
	s_CPU->GetDataRegister()->SetEnable(true);
	s_CPU->GetDataRegister()->SetOutputEnable(true);

	s_CPU->GetInstructionRegister()->SetEnable(false);

	s_CPU->GetProgramCounter()->SetEnable(true);

	s_CPU->GetMultiplexer()->SetSelect(false);

	s_CPU->GetAddressRegister()->SetEnable(false);
	s_CPU->GetAddressRegister()->SetOutputEnable(false);

	s_CPU->GetAccumulator()->SetEnable(true);
	s_CPU->GetAccumulator()->SetOutputEnable(false);

	s_CPU->GetALU()->SetFunction0(false);
	s_CPU->GetALU()->SetFunction1(false);
	s_CPU->GetALU()->SetFunction2(false);

	uint16_t s_Data;
	s_CPU->GetAccumulator()->Read(s_Data);

	if (s_Data == 0)
		s_CPU->GetDataBus()->Tick();

	m_CurrentState = 0;
}


void ControlUnit::TriggerCompPostExecute()
{
	CPU* s_CPU = VM::GetInstance()->GetCPU();
	Memory* s_Memory = VM::GetInstance()->GetMemory();

	s_Memory->SetReadWrite(false);
	s_Memory->SetChipSelect(true);
	s_Memory->SetOutputEnable(true);

	s_CPU->GetDataRegister()->SetDirection(false);
	s_CPU->GetDataRegister()->SetEnable(false);
	s_CPU->GetDataRegister()->SetOutputEnable(true);

	s_CPU->GetInstructionRegister()->SetEnable(false);

	s_CPU->GetProgramCounter()->SetEnable(false);

	s_CPU->GetMultiplexer()->SetSelect(false);

	s_CPU->GetAddressRegister()->SetEnable(false);
	s_CPU->GetAddressRegister()->SetOutputEnable(false);

	s_CPU->GetAccumulator()->SetEnable(true);
	s_CPU->GetAccumulator()->SetOutputEnable(false);

	s_CPU->GetALU()->SetFunction0(true);
	s_CPU->GetALU()->SetFunction1(true);
	s_CPU->GetALU()->SetFunction2(false);

	s_CPU->GetALU()->Tick();

	m_CurrentState = 0;
}

void ControlUnit::TriggerRShiftPostExecute()
{
	CPU* s_CPU = VM::GetInstance()->GetCPU();
	Memory* s_Memory = VM::GetInstance()->GetMemory();

	s_Memory->SetReadWrite(false);
	s_Memory->SetChipSelect(true);
	s_Memory->SetOutputEnable(true);

	s_CPU->GetDataRegister()->SetDirection(false);
	s_CPU->GetDataRegister()->SetEnable(false);
	s_CPU->GetDataRegister()->SetOutputEnable(true);

	s_CPU->GetInstructionRegister()->SetEnable(false);

	s_CPU->GetProgramCounter()->SetEnable(false);

	s_CPU->GetMultiplexer()->SetSelect(false);

	s_CPU->GetAddressRegister()->SetEnable(false);
	s_CPU->GetAddressRegister()->SetOutputEnable(false);

	s_CPU->GetAccumulator()->SetEnable(true);
	s_CPU->GetAccumulator()->SetOutputEnable(false);

	s_CPU->GetALU()->SetFunction0(false);
	s_CPU->GetALU()->SetFunction1(false);
	s_CPU->GetALU()->SetFunction2(true);

	s_CPU->GetALU()->Tick();

	m_CurrentState = 0;
}