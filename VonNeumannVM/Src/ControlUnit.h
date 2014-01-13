#pragma once

#include "stdafx.h"

#include "Interfaces/ITickable.h"
#include "Operation.h"

class ControlUnit : public ITickable
{
public:
	ControlUnit();

public:
	void Tick();
	void WriteOpcode(Opcode p_Opcode);

private:
	void TriggerFetch();
	void TriggerPreExecute();
	void TriggerPostExecute();

	void TriggerLoadPostExecute();
	void TriggerAddPostExecute();
	void TriggerStorePostExecute();
	void TriggerAndPostExecute();
	void TriggerJumpPostExecute();
	void TriggerJumpzPostExecute();
	void TriggerCompPostExecute();
	void TriggerRShiftPostExecute();

private:
	Opcode m_CurrentOpcode;
	int m_CurrentState;
};