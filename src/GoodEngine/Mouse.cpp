#include "Mouse.h"

namespace goodengine {

	bool Mouse::getMouseButton(int _button)
	{
		for (int i = 0; i < mouseButtons.size(); i++)
		{
			if (mouseButtons.at(i) == _button) return true;
		}
		return false;
	}

	bool Mouse::getMouseButtonDown(int _button)
	{
		for (int i = 0; i < mouseButtonsPressed.size(); i++)
		{
			if (mouseButtonsPressed.at(i) == _button) return true;
		}
		return false;
	}

	bool Mouse::getMouseButtonUp(int _button)
	{
		for (int i = 0; i < mouseButtonsReleased.size(); i++)
		{
			if (mouseButtonsReleased.at(i) == _button) return true;
		}
		return false;
	}

	glm::vec2 Mouse::getMousePosition()
	{
		return glm::vec2(mouseX, mouseY);
	}
}