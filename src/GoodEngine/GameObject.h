#include <memory>
#include <vector>

namespace goodengine {

	class Core;
	class Component;

	class GameObject
	{
	public:
		friend class goodengine::Core;

		// getCore()

		void tick();

		// display()

		template <typename T> std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			Components.push_back(rtn);

			return rtn;
		}

	protected:
		std::weak_ptr<Core> core;

		std::vector<std::shared_ptr<Component>> Components;
	};

}