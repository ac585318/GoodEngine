#pragma once

#include <memory>
#include <vector>

namespace goodengine {

	class Core;
	class Component;

	class GameObject
	{
	public:
		friend class goodengine::Core;
		
		std::shared_ptr<Core> getCore();
		void tick();
		void display();

		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			// Set rtn parent...
			rtn->gameObject = self;

			Components.push_back(rtn);

			return rtn;
		}

		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (int i = 0; i < Components.size(); i++)
			{
				std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(Components.at(i));

				if (rtn)
				{
					return rtn;
				}
			}

			throw Exception("Failed to find specified component");
		}

	protected:
		std::weak_ptr<Core> core;
		std::weak_ptr<GameObject> self;

		std::vector<std::shared_ptr<Component>> Components;
	};

}