#include "Component.h"
namespace goodengine {

	//std::shared_ptr<GameObject> Component::getGameObject()
	//{

	//}

	void Component::onInit()
	{
		std::cout << "INIT" << std::endl;
	}
	void Component::onBegin()
	{
		std::cout << "BEGIN" << std::endl;
	}
	void Component::onTick()
	{
		std::cout << "TICK" << std::endl;
	}
	void Component::onDisplay()
	{
		std::cout << "DISPLAY" << std::endl;
	}

}