#pragma once

class IRegister
{
public:
	virtual void SetEnable(bool p_Enabled) = 0;
	virtual bool GetEnable() = 0;
};