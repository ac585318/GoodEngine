#include <GoodEngine/Component.h>

#include <rend/rend.h>
#define RIGHT		glm::vec3(1,0,0)
#define LEFT		glm::vec3(-1,0,0)
#define UP			glm::vec3(0,1,0)
#define DOWN		glm::vec3(0,-1,0)
#define FORWARD		glm::vec3(0,0,1)
#define BACK		glm::vec3(0,0,-1)

namespace goodengine {

	///
	/// A Transform Component containing position, rotation and scale values.
	/// All GameObject objects are initialized to have this.
	/// Scale values cannot yet be adjusted.
	///
	class Transform : public Component
	{
	public:

		///
		/// \brief Get the position value
		/// \return a vec3 for X, Y and Z position coordinates
		///
		glm::vec3 getPosition();

		///
		/// \brief Get the rotation value.
		/// \return a vec3 for X, Y and Z rotation values
		///
		glm::vec3 getRotation();

		///
		/// \brief Set the position value
		/// \param _pos a vec3 for X, Y and Z position coordinates
		///
		void setPosition(glm::vec3 _pos);

		///
		/// \brief Set the position value
		/// \param _x float for the X position value
		/// \param _y float for the Y position value
		/// \param _z float for the Z position value
		///
		void setPosition(float _x, float _y, float _z);

		///
		/// \brief Move the position in a given direction
		///
		/// Can use pre-defined vectors UP , DOWN , LEFT , RIGHT , FORWARD , BACK
		///
		/// \param _direction a vec3 defining a direction to move the position in
		/// \param _amount float for the amount of movement in the direction
		///
		void movePosition(glm::vec3 _direction, float _amount);

		///
		/// \brief Set the rotation value. The value is internally used as radians
		/// \param _rot a vec3 for X, Y and Z rotation values
		///
		void setRotation(glm::vec3 _rot);

		///
		/// \brief Set the rotation value. The value is internally used as radians
		/// \param _x float for the X rotation value
		/// \param _y float for the Y rotation value
		/// \param _z float for the Z rotation value
		///
		void setRotation(float _x, float _y, float _z);

		///
		/// \brief Add to the current rotation value. The value is internally used as radians
		/// \param _rot a vec3 for X, Y and Z rotation values to add
		///
		void addRotation(glm::vec3 _rot);

		///
		/// \brief generate and return a model matrix
		/// \return glm::mat4 of the model matrix
		///
		glm::mat4 getModel();

	private:
		friend class goodengine::GameObject;
		void onInit();

		glm::vec3 position;
		glm::vec3 rotation;
		glm::vec3 scale;

		glm::mat4 model;
	};
}