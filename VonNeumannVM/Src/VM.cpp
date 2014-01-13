#include "VM.h"

#include <string>
#include <iostream>
#include <sstream>

#include "OpcodeConverter.h"

#pragma region Singleton

VM* VM::m_Instance = NULL;

VM* VM::GetInstance()
{
	if (m_Instance == NULL)
		m_Instance = new VM();

	return m_Instance;
}

#pragma endregion

VM::VM()
	: m_Memory(8192), m_TickCount(0)
{
	m_AddressBus.ConnectReadable(GetCPU()->GetAddressRegister());
	m_AddressBus.ConnectWriteable(GetMemory()->GetAddressHolder());

	m_DataBus.ConnectDataRegister(GetCPU()->GetDataRegister(), true);

	m_DataBus.ConnectWriteable(GetMemory());
	m_DataBus.ConnectReadable(GetMemory());
}

void VM::Start(const std::string& p_Input)
{
	if (p_Input.size() > 0)
	{
		auto s_Operations = OpcodeConverter::ConvertFile(p_Input);

		for (int i = 0; i < s_Operations.size(); ++i)
		{
			m_Memory.WriteUnsafe(i, s_Operations[i].GetData());
		}
	}


	while (true)
	{
		GetCPU()->Process();

		Clear();
		PrintState();

		while (ReadInput())
		{
			PrintState();
		}

		++m_TickCount;
	}
}

void VM::Clear()
{
	for (int i = 0; i < 100; ++i)
		printf("\n");
}

void VM::PrintState()
{
	printf("Tick: %d\n", m_TickCount);
	printf("===============================================================================\n");
	printf("= ALU - F0(%d) F1(%d) F2(%d) | MEM - OE(%d) CS(%d) RW(%d) | DR - EN(%d) OE(%d) DI(%d)  =\n", GetCPU()->GetALU()->GetFunction0(), GetCPU()->GetALU()->GetFunction1(), 
		GetCPU()->GetALU()->GetFunction2(), GetMemory()->GetOutputEnable(), GetMemory()->GetChipSelect(), GetMemory()->GetReadWrite(), GetCPU()->GetDataRegister()->GetEnable(), 
		GetCPU()->GetDataRegister()->GetOutputEnable(), GetCPU()->GetDataRegister()->GetDirection());
	printf("===============================================================================\n");
	printf("= AR - EN(%d) OE(%d) | AC - EN(%d) OE(%d) | PC - EN(%d) | IR - EN(%d) | MX - SL(%d)  =\n", GetCPU()->GetAddressRegister()->GetEnable(), 
		GetCPU()->GetAddressRegister()->GetOutputEnable(), GetCPU()->GetAccumulator()->GetEnable(), GetCPU()->GetAccumulator()->GetOutputEnable(),
		GetCPU()->GetProgramCounter()->GetEnable(), GetCPU()->GetInstructionRegister()->GetEnable(), GetCPU()->GetMultiplexer()->GetSelect());
	printf("===============================================================================\n");
	printf("= ALU_A(0x%04X)  |  ALU_B(0x%04X)  |  AC(0x%04X)  |  DR(0x%04X)  | PC(0x%04X) =\n", GetCPU()->GetALU()->GetA(), GetCPU()->GetALU()->GetB(), 
		GetCPU()->GetAccumulator()->ReadUnsafe(), GetCPU()->GetDataRegister()->ReadUnsafe(), GetCPU()->GetProgramCounter()->ReadUnsafe());
	printf("===============================================================================\n");
	printf("=        AR(0x%04X)        |        IR(0x%02X)        |        MEM(0x%04X)      =\n", GetCPU()->GetAddressRegister()->ReadUnsafe(), GetCPU()->GetInstructionRegister()->ReadUnsafe(), GetMemory()->GetAddressHolder()->GetAddress());
	printf("===============================================================================\n");
}

bool VM::ReadInput()
{
	std::string s_Input;
	getline(std::cin, s_Input);

	if (s_Input.size() == 0)
		return false;

	Clear();

	std::stringstream s_Stream(s_Input);
	uint16_t s_Address, s_Data;

	if (s_Input.find(" = ") != std::string::npos)
	{
		std::string s_Equals;
		s_Stream >> s_Address >> s_Equals >> s_Data;

		GetMemory()->WriteUnsafe(s_Address, s_Data);

		return true;
	}

	s_Stream >> s_Address;
	GetMemory()->ReadUnsafe(s_Address, s_Data);

	printf("%04X\t%02X %02X ; %s\n\n\n\n\n\n\n\n\n\n\n\n\n\n", s_Address, s_Data >> 8, s_Data & 0x11FF, OpcodeConverter::Convert(Operation(s_Data)).c_str());

	return true;
}