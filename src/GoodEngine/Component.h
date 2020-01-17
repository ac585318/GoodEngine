#pragma once
#ifndef GOODENGINE_COMPONENT_H
#define GOODENGINE_COMPONENT_H

#include <memory>
#include <iostream>

namespace goodengine {

	class Core;
	class GameObject;
	class Transform;
	class Resources;
	class Keyboard;
	class Mouse;

	///
	/// A base class for components. Components are members of GameObject objects.
	/// This class should be inherited from to create unique game components, features/mechanics and scenes.
	/// Components are updated within GameObject objects, GameObject is updated within Core once per frame.
	///
	class Component
	{
	public:
		friend class goodengine::GameObject;

		///
		/// \brief Returns a reference to the Core object
		/// \return A reference to Core
		///
		std::shared_ptr<Core> getCore();

		///
		/// \brief Returns the GameObject object this component is a member of
		/// \return A reference to the GameObject
		///
		std::shared_ptr<GameObject> getGameObject();

		///
		/// \brief Returns the Resources object
		/// \return A reference to Resources
		///
		std::shared_ptr<Resources> getResources();

		///
		/// \brief Returns the Keyboard object
		/// \return A reference to Keyboard
		///
		std::shared_ptr<Keyboard> getKeyboard();

		///
		/// \brief Returns the Mouse object
		/// \return A reference to Mouse
		///
		std::shared_ptr<Mouse> getMouse();

		///
		/// \brief A shortcut function to get the Transform Component from the GameObject
		/// \return A Transform Component from the parent GameObject
		///
		std::shared_ptr<Transform> getTransform();

	protected:
		std::weak_ptr<GameObject> gameObject;		///< weak pointer reference to the owning GameObject
		bool alive = true;							///< bool to check if the component should be kept alive if true, or destroyed if false

		///
		/// \brief a virtual initialize function
		///
		/// Runs once when a Component is added to a GameObject
		///
		virtual void onInit();

		// Could either run at the start of the game or when the object is made alive/active
		//virtual void onBegin();

		///
		/// \brief a virtual "onTick" function
		///
		/// Runs once per every frame
		///
		virtual void onTick();

		///
		/// \brief a virtual "onDisplay" function
		///
		/// Runs once per every frame, after onTick()
		///
		virtual void onDisplay();

		///
		/// \brief a virtual "onGui" function
		///
		/// Runs once per every frame, after onTick() and onDisplay()
		///
		virtual void onGui();
	};
}

#endif