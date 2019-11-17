#include "GameObject.h"
#include "Component.h"

namespace goodengine {

	std::shared_ptr<Core> GameObject::getCore()
	{
		return core.lock();
	}

	void GameObject::tick()
	{
		for (size_t i = 0; i < Components.size(); i++)
		{
			Components.at(i)->onTick();
		}
	}

	void GameObject::display()
	{
		for (size_t i = 0; i < Components.size(); i++)
		{
			Components.at(i)->onDisplay();
		}
	}
}

