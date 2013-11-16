#include "VM.h"
#include <string.h>

#include "Operation.h"
#include "Memory.h"

int main()
{
	Operation s_Operation(JUMPZ, 1583);
	printf("%X %X %X\n", s_Operation.GetData(), s_Operation.GetOpcode(), s_Operation.GetAddress());

	Memory s_Memory(8192);

	s_Memory.Write(0, Operation(JUMPZ, 1583).GetData());

	unsigned short s_Data;
	s_Memory.Read(0, s_Data);
	Operation s_NewOperation(s_Data);


	printf("%X %X %X\n", s_NewOperation.GetData(), s_NewOperation.GetOpcode(), s_NewOperation.GetAddress());

	for(;;);

	return 0;
}