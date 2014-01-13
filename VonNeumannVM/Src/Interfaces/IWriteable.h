#pragma once

#include "../stdafx.h"

class IWriteable
{
public:
	virtual bool Write(uint16_t p_Data) = 0;
	virtual bool CanWrite() = 0;
};