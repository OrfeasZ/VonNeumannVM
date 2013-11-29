#pragma once

#include "../stdafx.h"

#include "OutputRegister.h"
#include "InputRegister.h"

class Accumulator : public InputRegister, public OutputRegister
{

};