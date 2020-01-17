#include <vector>
#include <glm/glm.hpp>

namespace goodengine {

	///
	/// A mouse handling class using SDL mouse event codes.
	/// Use to check mouse position or if a mouse button is being held, pressed or released.
	///
	class Mouse
	{
	public:
		///
		/// \brief Check to see if a mouse button is being held
		/// \param _button the SDL mouse button event to check
		/// \return bool, true if held, false otherwise
		///
		bool getMouseButton(int _button);

		///
		/// \brief Check to see if a mouse button has been pressed
		/// \param _button the SDL mouse button event to check
		/// \return bool, true if pressed, false otherwise
		///
		bool getMouseButtonDown(int _button);

		///
		/// \brief Check to see if a mouse button has been released
		/// \param _button the SDL mouse button event to check
		/// \return bool, true if released, false otherwise
		///
		bool getMouseButtonUp(int _button);

		///
		/// \brief Returns the current mouse position
		/// \return glm::vec2 containing the X and Y coordinates of the mouse position
		///
		glm::vec2 getMousePosition();

	private:
		friend class Core;
		std::vector<int> mouseButtons;
		std::vector<int> mouseButtonsPressed;
		std::vector<int> mouseButtonsReleased;
		int mouseX;
		int mouseY;
	};
}