#include <vector>

namespace goodengine {

	class Keyboard
	{
	public:

		bool getKey(int _keyCode);
		bool getKeyDown(int _keyCode);
		bool getKeyUp(int _keyCode);

	private:
		friend class Core;
		std::vector<int> keys;
		std::vector<int> keysPressed;
		std::vector<int> keysReleased;
	};

}