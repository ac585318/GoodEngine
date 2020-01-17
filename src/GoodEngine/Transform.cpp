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

	void Transform::setPosition(float _x, float _y, float _z)
	{
		position = glm::vec3(_x, _y, _z);
	}

	void Transform::movePosition(glm::vec3 _direction, float _amount)
	{
		// right	= (1,0,0)
		// up		= (0,1,0)
		// forward	= (0,0,1)

		glm::mat4 m(1.0f);

		m = glm::rotate(m, glm::radians(rotation.x), glm::vec3(1, 0, 0));
		m = glm::rotate(m, glm::radians(rotation.y), glm::vec3(0, 1, 0));
		m = glm::rotate(m, glm::radians(rotation.z), glm::vec3(0, 0, 1));
		m = glm::translate(m, _direction);

		position += glm::vec3(m * glm::vec4(0, 0, 0, _amount));
	}

	void Transform::setRotation(glm::vec3 _rot)
	{
		glm::vec3 rot = _rot;
		// Clamp to 360
		rot.x = (rot.x > 360) ? rot.x - 360 :	(rot.x < -360) ? rot.x + 360 : rot.x;
		rot.y = (rot.y > 360) ? rot.y - 360 :	(rot.y < -360) ? rot.y + 360 : rot.y;
		rot.z = (rot.z > 360) ? rot.z - 360 :	(rot.z < -360) ? rot.z + 360 : rot.z;
		rotation = rot;
	}

	void Transform::setRotation(float _x, float _y, float _z)
	{
		glm::vec3 rot = glm::vec3(_x, _y, _z);
		// Clamp to 360
		rot.x = (rot.x > 360) ? rot.x - 360 : (rot.x < -360) ? rot.x + 360 : rot.x;
		rot.y = (rot.y > 360) ? rot.y - 360 : (rot.y < -360) ? rot.y + 360 : rot.y;
		rot.z = (rot.z > 360) ? rot.z - 360 : (rot.z < -360) ? rot.z + 360 : rot.z;
		rotation = rot;
	}

	void Transform::addRotation(glm::vec3 _rot)
	{
		rotation += _rot;
		// Clamp to 360
		rotation.x = (rotation.x > 360) ? rotation.x - 360 :	(rotation.x < -360) ? rotation.x + 360 : rotation.x;
		rotation.y = (rotation.y > 360) ? rotation.y - 360 :	(rotation.y < -360) ? rotation.y + 360 : rotation.y;
		rotation.z = (rotation.z > 360) ? rotation.z - 360 :	(rotation.z < -360) ? rotation.z + 360 : rotation.z;
	}

	glm::mat4 Transform::getModel()
	{
		return glm::translate(glm::mat4(1.0f), position) *
			glm::rotate(glm::mat4(1.0f), glm::radians(rotation.x), glm::vec3(1, 0, 0))*
			glm::rotate(glm::mat4(1.0f), glm::radians(rotation.y), glm::vec3(0, 1, 0))*
			glm::rotate(glm::mat4(1.0f), glm::radians(rotation.z), glm::vec3(0, 0, 1))*
			glm::scale(glm::mat4(1.0f), scale);
	}
}