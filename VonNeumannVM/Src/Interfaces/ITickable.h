#pragma once

#include "../stdafx.h"

class ITickable
{
public:
	virtual void Tick() = 0;
};