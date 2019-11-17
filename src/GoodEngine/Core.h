#include <memory>
#include <vector>

#include <SDL2/SDL.h>
#include <GL/glew.h>

#include <exception>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

namespace goodengine {

	class GameObject;

	class Core
	{
	public:
		~Core();

		static std::shared_ptr<Core> initialize();			// Static also makes this function more accessible for main.cpp
		std::shared_ptr<GameObject> addGameObject();

		void run();

	protected:
		friend class goodengine::GameObject;
		std::vector<std::shared_ptr<GameObject>> GameObjects;

	private:
		SDL_Window *window;
		std::weak_ptr<Core> self;

		bool quit;
	};

}