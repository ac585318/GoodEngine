#pragma once

#include "Component.h"

#include <rend/rend.h>

namespace goodengine {

	class Transform : public Component
	{
	public:
		void onInit();
		//getModel
		glm::vec3 getPosition();
		void setPosition(glm::vec3 _pos);

	private:
		glm::vec3 position;
		glm::vec3 rotation;
		//vec3 scale;
	};
}