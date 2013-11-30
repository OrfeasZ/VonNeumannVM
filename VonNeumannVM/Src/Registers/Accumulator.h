#pragma once

#include "../stdafx.h"
#include "../ITickable.h"

#include "OutputRegister.h"
#include "InputRegister.h"

class Accumulator : public InputRegister, public OutputRegister, public ITickable
{

};