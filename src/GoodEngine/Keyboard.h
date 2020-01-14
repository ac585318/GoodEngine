#include <vector>

namespace goodengine {

	///
	/// A keyboard handling class using SDL keycodes
	///
	class Keyboard
	{
	public:
		///
		/// \brief Check to see if a key is being held
		/// \param _keyCode the SDL keycode to check
		/// \return bool, true if held, false otherwise
		///
		bool getKey(int _keyCode);

		///
		/// \brief Check to see if a key has been pressed
		/// \param _keyCode the SDL keycode to check
		/// \return bool, true if pressed, false otherwise
		///
		bool getKeyDown(int _keyCode);

		///
		/// \brief Check to see if a key has been released
		/// \param _keyCode the SDL keycode to check
		/// \return bool, true if released, false otherwise
		///
		bool getKeyUp(int _keyCode);

	private:
		friend class Core;
		std::vector<int> keys;
		std::vector<int> keysPressed;
		std::vector<int> keysReleased;
	};

}