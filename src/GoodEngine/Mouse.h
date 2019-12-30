#include <vector>
#include <glm/glm.hpp>

namespace goodengine {

	class Mouse
	{
	public:

		bool getMouseButton(int _button);
		bool getMouseButtonDown(int _button);
		bool getMouseButtonUp(int _button);
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