#pragma once

#include "stdafx.h"
#include "VM.h"

int main(int argc, char* argv[])
{
	std::string s_Input = "";

	if (argc >= 2)
		s_Input = argv[1];

	VM::GetInstance()->Start(s_Input);

	return 0;
}