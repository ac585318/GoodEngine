#pragma once

#include <memory>
#include <iostream>

namespace goodengine {

	class GameObject;

	class Component
	{
	public:
		friend class goodengine::GameObject;

		// Do get functions need an argument?
		//std::shared_ptr<GameObject> getGameObject();

		// getCore()

	protected:
		std::weak_ptr<GameObject> gameObject;

		virtual void onInit();
		virtual void onBegin();
		virtual void onTick();
		virtual void onDisplay();
	};

}