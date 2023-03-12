#pragma once

namespace MyStaticVar
{
	bool keepMouseWheelUp = false;
	bool keepMouseWheelDown = false;

	bool skipMouseWheelUp()
	{
		if (keepMouseWheelUp)
			return true;
		keepMouseWheelUp = true;
		keepMouseWheelDown = false;
		return false;
	}

	bool skipMouseWheelDown()
	{
		if (keepMouseWheelDown)
			return true;
		keepMouseWheelUp = false;
		keepMouseWheelDown = true;
		return false;
	}

	void otherOperation()
	{
		keepMouseWheelUp = false;
		keepMouseWheelDown = false;
	}

}; // namespace MyStaticVar