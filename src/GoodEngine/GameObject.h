#include <memory>
#include <vector>

namespace goodengine {

	class Core;
	class Component;
	class Transform;

	///
	/// A class for game objects and entities. Contains a vector of Component type objects.
	/// They are initialized with a Transform component.
	/// GameObject objects are owned and updated within Core.
	///
	class GameObject
	{
	public:
		friend class Core;

		///
		/// \brief Returns a reference to the Core object
		/// \return A reference to Core
		///
		std::shared_ptr<Core> getCore();

		///
		/// \brief Add a specified Component type object to this GameObject
		///
		/// Use this to add child classes of Component to the GameObject
		///
		/// \return A reference to the specified Component class or child type object
		///
		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			std::shared_ptr<T> rtn = std::make_shared<T>();

			// Set rtn parent
			rtn->gameObject = self;

			Components.push_back(rtn);

			rtn->onInit();

			return rtn;
		}

		///
		/// \brief Add a specified Component type class to this GameObject
		///
		/// Use this to get child objects of Component to the GameObject
		///
		/// \return A reference to the specified Component class or child type object
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
			throw rend::Exception("Failed to find specified component");
		}

		///
		/// \brief A shortcut function to get the Transform Component from the GameObject
		/// \return A Transform Component from the parent GameObject
		///
		std::shared_ptr<Transform> getTransform();

	private:
		void tick();
		void display();
		//bool alive = true;	// Something to implement later, similar to component, remove GO and 

		std::weak_ptr<Core> core;
		std::weak_ptr<GameObject> self;

		std::vector<std::shared_ptr<Component>> Components;
	};
}