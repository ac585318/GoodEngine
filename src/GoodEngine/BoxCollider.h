#include <GoodEngine/Component.h>
#include <glm/glm.hpp>

namespace goodengine {

	///
	/// Adds a BoxCollider to a GameObject.
	/// A box / cuboide with basic collision against other BoxColliders.
	/// Cannot be rotated.
	///
	class BoxCollider : public Component
	{
	public:
		///
		/// \brief Set the size of the box
		/// \param _size A vec3 for width, height and depth to set the box's size to
		///
		void setSize(glm::vec3 _size);

		///
		/// \brief Set the offset of the box
		/// \param _offset A vec3 for X, Y and Z to set the box's offset position to
		///
		void setOffset(glm::vec3 _offset);

		///
		/// \brief Set if the collider should be a static collider. False by default
		///
		/// Static colliders are colliders that do not reposition themselves upon being collided against.
		/// Use this for stationary objects such as walls or ground.
		/// GameObject objects set to have a static collider should generally not have their transform modified
		///
		/// \param _b A bool to set if the collider should be static or not
		///
		void isStaticCollider(bool _b) { staticCollider = _b; }

		///
		/// \brief Set another BoxCollider as the trigger for this BoxCollider
		///
		/// TriggerHit is set to true, for one tick, if this BoxCollider collides with it's trigger.
		/// To add multiple triggers you may add more BoxCollider components to the GameObject.
		/// There is no trigger set by default
		///
		/// \param _triggerObject a weak pointer reference to the trigger BoxCollider
		///
		void setTriggerObject(std::weak_ptr<BoxCollider> _triggerObject) { triggerObject = _triggerObject; }

		///
		/// \brief Check if this BoxCollider collided against it's trigger this frame
		/// \return Bool, true if there was a collision against trigger this time
		///
		bool getTriggerHit() { return triggerHit; }

	private:
		friend class GameObject;
		void onInit();
		void onTick();

		glm::vec3 size;
		glm::vec3 offset;
		glm::vec3 lastPosition;
		bool staticCollider;
		std::weak_ptr<BoxCollider> triggerObject;
		bool triggerHit;

		bool isColliding(glm::vec3 _pos, glm::vec3 _size);
		glm::vec3 getCollisionResponse(glm::vec3 _pos, glm::vec3 _offset, glm::vec3 _size);
	};
}