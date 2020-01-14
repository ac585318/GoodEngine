#include <GoodEngine/Component.h>
#include <glm/glm.hpp>

namespace goodengine {

	class Transform;

	///
	/// A Camera Component class.
	/// Uses the Transform (position and rotation) of the GameObject it belongs to.
	///
	class Camera : public Component
	{
	public:
		///
		/// \brief Returns the projection matrix, the matrix cannot yet be modified
		/// \return glm::mat4 of the projection matrix
		///
		glm::mat4 getProjection() { return projectionMatrix; }

		///
		/// \brief Updates and returns the view matrix
		/// \return glm::mat4 of the view matrix
		///
		glm::mat4 getView();

		///
		/// \brief A shortcut function to get the Transform Component from the parent GameObject
		/// \return Shared pointer to the Transform Component
		///
		std::shared_ptr<Transform> getTransform();

	private:
		friend class goodengine::GameObject;
		void onInit();

		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix;
	};

}