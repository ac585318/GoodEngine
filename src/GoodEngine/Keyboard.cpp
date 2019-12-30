#include "Keyboard.h"

namespace goodengine {

	bool Keyboard::getKey(int _keyCode)
	{
		for (int i = 0; i < keys.size(); i++)
		{
			if (keys.at(i) == _keyCode) return true;
		}
		return false;
	}

	bool Keyboard::getKeyDown(int _keyCode)
	{
		for (int i = 0; i < keysPressed.size(); i++)
		{
			if (keysPressed.at(i) == _keyCode) return true;
		}
		return false;
	}

	bool Keyboard::getKeyUp(int _keyCode)
	{
		for (int i = 0; i < keysReleased.size(); i++)
		{
			if (keysReleased.at(i) == _keyCode) return true;
		}
		return false;
	}

}