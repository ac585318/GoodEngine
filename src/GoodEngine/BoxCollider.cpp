#include "BoxCollider.h"
#include "Core.h"
#include "GameObject.h"
#include "Transform.h"

namespace goodengine {

	void BoxCollider::onInit()
	{
		size = glm::vec3(1, 1, 1);
		lastPosition = getGameObject()->getComponent<Transform>()->getPosition();
	}

	void BoxCollider::setSize(glm::vec3 _size)
	{
		this->size = _size;
	}

	void BoxCollider::setOffset(glm::vec3 _offset)
	{
		this->offset = _offset;
	}

	void BoxCollider::onTick()
	{
		//	BOX COLLISION
		std::vector<std::shared_ptr<GameObject>> boxObjVec;

		getCore()->getGameObjects<BoxCollider>(boxObjVec);

		//									TRY SIMPLIFY WITH CODE IN COMPONENT.H 26
		glm::vec3 boxPos = getGameObject()->getComponent<Transform>()->getPosition() + offset;

		for (std::vector<std::shared_ptr<GameObject>>::iterator it = boxObjVec.begin();
			it != boxObjVec.end(); it++)
		{
			// if iterator == self
			if (*it == getGameObject())
			{
				continue;
			}

			std::shared_ptr<BoxCollider> iterBox = (*it)->getComponent<BoxCollider>();

			glm::vec3 respPos = iterBox->getCollisionResponse(boxPos, size);
			boxPos = respPos;
			boxPos = boxPos - offset;
			getGameObject()->getComponent<Transform>()->setPosition(boxPos);
			lastPosition = boxPos;
		}
	}

	bool BoxCollider::isColliding(glm::vec3 _pos, glm::vec3 _size)
	{
		glm::vec3 a = getGameObject()->getComponent<Transform>()->getPosition() + offset;
		glm::vec3 &as = this->size;
		glm::vec3 &b = _pos;
		glm::vec3 &bs = _size;

		if (a.x > b.x) // a right of b
		{
			if (a.x - as.x > b.x + bs.x) // left edge of a greater than right edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.x - bs.x > a.x + as.x)
			{
				return false;
			}
		}

		if (a.z > b.z) // a front of b
		{
			if (a.z - as.z > b.z + bs.z) // back edge of a greater than front edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.z - bs.z > a.z + as.z)
			{
				return false;
			}
		}

		if (a.y > b.y) // a above b
		{
			if (a.y - as.y > b.y + bs.y) // bottom edge of a greater than top edge of b (not colliding)
			{
				return false;
			}
		}
		else
		{
			if (b.y - bs.y > a.y + as.y)
			{
				return false;
			}
		}

		return true;
	}

	// Returns where _pos should be after collision
	glm::vec3 BoxCollider::getCollisionResponse(glm::vec3 _pos, glm::vec3 _size)
	{
		float amount = 0.05f;
		float step = 0.05f;

		while (true)
		{
			if (!isColliding(_pos, _size)) break;
			_pos.x += amount;
			if (!isColliding(_pos, _size)) break;
			_pos.x -= amount;
			_pos.x -= amount;
			if (!isColliding(_pos, _size)) break;
			_pos.x += amount;
			_pos.z += amount;
			if (!isColliding(_pos, _size)) break;
			_pos.z -= amount;
			_pos.z -= amount;
			if (!isColliding(_pos, _size)) break;
			_pos.z += amount;
			_pos.y += amount;
			if (!isColliding(_pos, _size)) break;
			_pos.y -= amount;
			_pos.y -= amount;
			if (!isColliding(_pos, _size)) break;
			_pos.y += amount;
			amount += step;
		}

		return _pos;
	}

}