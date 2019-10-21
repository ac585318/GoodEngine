#include "Core.h"
#include "GameObject.h"

namespace goodengine {

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();

		return rtn;
	}

	std::shared_ptr<GameObject> Core::addGameObject()
	{
		std::shared_ptr<GameObject> rtn = std::make_shared<GameObject>();

		GameObjects.push_back(rtn);
		// get working
		// rtn->core = this;

		return rtn;
	}

	void Core::run()
	{
		//Go through gameobjects and call their tick functions?

		for (size_t i = 0; i < GameObjects.size(); i++)
		{
			// incomplete class type
			GameObjects.at(i)->tick();
		}
	}
}