#include "Camera.h"
#include "Core.h"
#include "GameObject.h"
#include "Transform.h"

namespace goodengine {

	void Camera::onInit()
	{
		projectionMatrix = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);
		// Use the Transform of the parent GameObject to use getModel and inverse it for the viewMatrix
		viewMatrix = glm::inverse(gameObject.lock()->getComponent<Transform>()->getModel());

		// Set cores weak pointer to this camera
		//gameObject.lock()->getCore()->setActiveCam(std::enable_shared_from_this());	// Needs improving, is done manually for now
	}

	glm::mat4 Camera::getView()
	{
		// Update viewMatrix and return
		viewMatrix = glm::inverse(gameObject.lock()->getComponent<Transform>()->getModel());
		return viewMatrix;
	}

	std::shared_ptr<Transform> Camera::getTransform()
	{
		// Could be slower to use than manual
		return gameObject.lock()->getComponent<Transform>();
	}
}