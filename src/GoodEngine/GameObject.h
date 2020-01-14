#include <memory>
#include <vector>
#include "Transform.h"
//#include <rend/rend.h>
//#include <GoodEngine\Exception.h>

namespace goodengine {

	class Core;
	class Component;

	///
	/// A class for game objects and entities. Contains a vector of Component.
	/// GameObject objects are owned and updated within Core.
	///
	class GameObject
	{
	public:
		friend class Core;
		///
		/// \brief Returns a pointer to the Core object
		/// \return Shared pointer to Core
		///
		std::shared_ptr<Core> getCore();

		///
		/// \brief Add a specified Component type class to this GameObject
		///
		/// Use this to add child classes of Component to the GameObject
		///
		/// \return Shared pointer to the specified Component class or child type
		///
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			// Set rtn parent
			rtn->gameObject = self;

			rtn->onInit();

			Components.push_back(rtn);

			return rtn;
		}

		///
		/// \brief Add a specified Component type class to this GameObject
		///
		/// Use this to get child classes of Component to the GameObject
		///
		/// \return Shared pointer to the specified Component class or child type
		///
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
			throw rend::Exception("Failed to find specified component");	// Something is wrong with using goodengine::exception, maybe because they use the same file names?
		}

	private:
		void tick();
		void display();

		std::weak_ptr<Core> core;
		std::weak_ptr<GameObject> self;

		std::vector<std::shared_ptr<Component>> Components;
	};

}