#pragma once

#include "../stdafx.h"

class IReadable
{
public:
	virtual bool Read(uint16_t& p_Data) = 0;
	virtual bool CanRead() = 0;
};