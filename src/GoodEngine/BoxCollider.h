#pragma once

#include <GoodEngine/Component.h>
#include <glm/glm.hpp>


namespace goodengine {

	class BoxCollider : public Component
	{
	public:

		void onInit();
		void setSize(glm::vec3 _size);
		void setOffset(glm::vec3 _offset);

	private:
		void onTick();

		glm::vec3 size;
		glm::vec3 offset;
		glm::vec3 lastPosition;

		bool isColliding(glm::vec3 _pos, glm::vec3 _size);
		glm::vec3 getCollisionResponse(glm::vec3 _pos, glm::vec3 _size);
	};

}