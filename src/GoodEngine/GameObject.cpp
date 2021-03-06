#include "GameObject.h"
#include "Component.h"
#include "Transform.h"

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
		// Erase component ptr if not alive, could be put at the end of display()?
		for (std::vector<std::shared_ptr<Component>>::iterator it = Components.begin(); it != Components.end();)
		{
			if (!(*it)->alive)
			{
				it = Components.erase(it);
			}
			else
			{
				it++;
			}
		}
	}

	void GameObject::display()
	{
		for (size_t i = 0; i < Components.size(); i++)
		{
			Components.at(i)->onDisplay();
		}
		for (size_t i = 0; i < Components.size(); i++)
		{
			Components.at(i)->onGui();
		}
	}

	std::shared_ptr<Transform> GameObject::getTransform()
	{
		// Could be slower to use than manual
		return getComponent<Transform>();
	}
}

