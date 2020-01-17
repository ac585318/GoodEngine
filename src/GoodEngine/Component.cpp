#include "Component.h"
#include "GameObject.h"
#include "Transform.h"
#include "Core.h"

namespace goodengine {

	std::shared_ptr<Core> Component::getCore()
	{
		return gameObject.lock()->getCore();
	}
	std::shared_ptr<GameObject> Component::getGameObject()
	{
		return gameObject.lock();
	}
	std::shared_ptr<Resources> Component::getResources()
	{
		return gameObject.lock()->getCore()->getResources();
	}
	std::shared_ptr<Keyboard> Component::getKeyboard()
	{
		return gameObject.lock()->getCore()->getKeyboard();
	}
	std::shared_ptr<Mouse> Component::getMouse()
	{
		return gameObject.lock()->getCore()->getMouse();
	}
	std::shared_ptr<Transform> Component::getTransform()
	{
		// Could be slower to use than manual
		return gameObject.lock()->getTransform();
	}
	void Component::onInit()
	{
		//std::cout << "INIT" << std::endl;
	}
	void Component::onTick()
	{
		//std::cout << "TICK" << std::endl;
	}
	void Component::onDisplay()
	{
		//std::cout << "DISPLAY" << std::endl;
	}
	void Component::onGui()
	{
		//std::cout << "DISPLAY" << std::endl;
	}
}