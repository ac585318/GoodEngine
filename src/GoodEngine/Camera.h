#include <GoodEngine/Component.h>
#include <glm/glm.hpp>

namespace goodengine {

	///
	/// A Camera Component class.
	/// Uses the Transform (position and rotation) of the GameObject it belongs to.
	///
	class Camera : public Component
	{
	public:
		///
		/// \brief Returns the projection matrix, the matrix cannot yet be modified
		/// \return A mat4 of the camera's projection matrix
		///
		glm::mat4 getProjection() { return projectionMatrix; }

		///
		/// \brief Updates and returns the view matrix
		/// \return A mat4 of the camera's view matrix
		///
		glm::mat4 getView();

	private:
		friend class goodengine::GameObject;
		void onInit();

		glm::mat4 projectionMatrix;
		glm::mat4 viewMatrix;
	};
}