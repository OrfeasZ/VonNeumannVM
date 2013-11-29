#pragma once

#include "../stdafx.h"

#include "OutputRegister.h"
#include "InputRegister.h"

class AddressRegister : public InputRegister, public OutputRegister
{

};