#pragma once
#include "Component.h"
#include "GameObject.h"
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
	void Component::onInit()
	{
		//std::cout << "INIT" << std::endl;
	}
	void Component::onBegin()
	{
		//std::cout << "BEGIN" << std::endl;
	}
	void Component::onTick()
	{
		//std::cout << "TICK" << std::endl;
	}
	void Component::onDisplay()
	{
		//std::cout << "DISPLAY" << std::endl;
	}

}