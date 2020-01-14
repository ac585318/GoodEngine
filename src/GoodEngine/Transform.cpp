#include "Transform.h"

namespace goodengine {

	void Transform::onInit()
	{
		position = glm::vec3(0, 0, 0);
		rotation = glm::vec3(0, 0, 0);
		scale = glm::vec3(1, 1, 1);

		model = glm::mat4(1.0f);
	}

	glm::vec3 Transform::getPosition()
	{
		return position;
	}

	glm::vec3 Transform::getRotation()
	{
		return rotation;
	}

	void Transform::setPosition(glm::vec3 _pos)
	{
		position = _pos;
	}

	void Transform::setRotation(glm::vec3 _rot)
	{
		rotation = _rot;
	}

	glm::mat4 Transform::getModel()
	{
		model = glm::translate(glm::mat4(1.0f), position);
		model = glm::rotate(model, rotation.y, glm::vec3(0, 1, 0));
		model = glm::scale(model, glm::vec3(scale.x, scale.y, scale.z));

		return model;
	}
}