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
		/// \param _size a vec3 for width, height and depth to set the box size to
		///
		void setSize(glm::vec3 _size);

		///
		/// \brief Set the offset of the box
		/// \param _offset a vec3 for X, Y and Z to set the box offset position to
		///
		void setOffset(glm::vec3 _offset);

	private:
		friend class goodengine::GameObject;
		void onInit();
		void onTick();

		glm::vec3 size;
		glm::vec3 offset;
		glm::vec3 lastPosition;

		bool isColliding(glm::vec3 _pos, glm::vec3 _size);
		glm::vec3 getCollisionResponse(glm::vec3 _pos, glm::vec3 _size);
	};

}