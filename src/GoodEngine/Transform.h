#pragma once
#ifndef GOODENGINE_TRANSFORM_H
#define GOODENGINE_TRANSFORM_H

#include "Component.h"

#include <rend/rend.h>

namespace goodengine {

	class Transform : public Component
	{
	public:
		void onInit();

		glm::vec3 getPosition();
		glm::vec3 getRotation();
		void setPosition(glm::vec3 _pos);
		void setRotation(glm::vec3 _rot);

		glm::mat4 getModel();

	private:
		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		glm::mat4 model;
	};
}

#endif