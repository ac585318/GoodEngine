#include "Transform.h"

namespace goodengine {

	void Transform::onInit()
	{
		position = glm::vec3(0, 0, 0);
		rotation = glm::vec3(0, 0, 0);
	}

	glm::vec3 Transform::getPosition()
	{
		return position;
	}

	void Transform::setPosition(glm::vec3 _pos)
	{
		position = _pos;
	}
}