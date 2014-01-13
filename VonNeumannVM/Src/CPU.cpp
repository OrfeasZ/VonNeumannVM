#include "CPU.h"

#include "VM.h"

CPU::CPU()
	: m_CurrentState(Fetch)
{
	m_DataBus.ConnectReadable(GetAccumulator());

	m_DataBus.ConnectWriteable(GetALU());
	m_DataBus.ConnectWriteable(GetInstructionRegister());
	m_DataBus.ConnectWriteable(GetProgramCounter());

	m_DataBus.ConnectDataRegister(GetDataRegister(), false);
}

void CPU::Process()
{
	m_ControlUnit.Tick();

	/*switch (m_CurrentState)
	{
	case Fetch:
	case Decode:
		m_ControlUnit.Tick();

		VM::GetInstance()->GetDataBus()->Tick();
		VM::GetInstance()->GetAddressBus()->Tick();
		m_DataBus.Tick();

		m_ALU.Tick();
		m_InstructionRegister.Tick();
		m_Multiplexer.Tick();

		break;

	case DataFetch:
		m_ControlUnit.Tick();

		VM::GetInstance()->GetDataBus()->Tick();
		VM::GetInstance()->GetAddressBus()->Tick();
		m_DataBus.Tick();

		m_ALU.Tick();

		break;

	case Execute:
		m_ControlUnit.Tick();

		VM::GetInstance()->GetDataBus()->Tick();
		VM::GetInstance()->GetAddressBus()->Tick();
		m_DataBus.Tick();

		m_ALU.Tick();

		break;

	case Store:
		m_ControlUnit.Tick();

		VM::GetInstance()->GetDataBus()->Tick();
		VM::GetInstance()->GetAddressBus()->Tick();
		m_DataBus.Tick();

		m_Multiplexer.Tick();

		break;
	}

	if (m_CurrentState == Fetch)
		m_ProgramCounter.Increment();

	m_CurrentState = (State)(((int) m_CurrentState) + 1);

	if (m_CurrentState == MaxStates)
		m_CurrentState = Fetch;*/
}