#pragma once
#ifndef GOODENGINE_COMPONENT_H
#define GOODENGINE_COMPONENT_H

#include <memory>
#include <iostream>

namespace goodengine {

	class Core;
	class GameObject;
	class Resources;
	class Keyboard;
	class Mouse;

	class Component
	{
	public:
		friend class goodengine::GameObject;
		std::shared_ptr<Core> getCore();
		std::shared_ptr<GameObject> getGameObject();
		std::shared_ptr<Resources> getResources();
		std::shared_ptr<Keyboard> getKeyboard();
		std::shared_ptr<Mouse> getMouse();

		//													TEST THIS
		//template <typename T>
		//std::shared_ptr<T> getComponent()
		//{
		//	return gameObject.lock()->getComponent<T>();
		//}

	protected:
		std::weak_ptr<GameObject> gameObject;
		bool alive = true;

		virtual void onInit();
		virtual void onBegin();
		virtual void onTick();
		virtual void onDisplay();

	private:


	};

}

#endif