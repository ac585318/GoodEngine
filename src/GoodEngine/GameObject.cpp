#include "GameObject.h"
#include "Component.h"

namespace goodengine {

	void GameObject::tick()
	{
		for (size_t i = 0; i < Components.size(); i++)
		{
			// incomplete class type
			Components.at(i)->onTick();
		}
	}

}

