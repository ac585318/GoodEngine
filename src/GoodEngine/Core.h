#include <memory>
#include <vector>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <rend/rend.h>

#include <AL/al.h>
#include <AL/alc.h>

#include <exception>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

namespace goodengine {

	class GameObject;
	class Resources;
	class Keyboard;
	class Mouse;
	class Enviroment;

	class Core
	{
	public:
		~Core();

		static std::shared_ptr<Core> initialize();			// Static also makes this function more accessible for main.cpp
		std::shared_ptr<GameObject> addGameObject();

		std::shared_ptr<Resources> getResources() { return resources; }
		std::shared_ptr<Keyboard> getKeyboard() { return keyboard; }
		std::shared_ptr<Mouse> getMouse() { return mouse; }
		std::shared_ptr<rend::Context> getContext() { return context; }
		
		std::vector<std::shared_ptr<GameObject>> getGameObjects() { return gameObjects; }

		// Pushes back game objects, into parameter, with a type of component
		template <typename T>
		std::shared_ptr<T> getGameObjects(std::vector<std::shared_ptr<GameObject>> &_rtn)
		{
			// clear in case the user isn't using a emptied list
			_rtn.clear();

			// For every gameObject in gameObjects
			for (int i = 0; i < gameObjects.size(); i++)
			{
				// for every component in gameObject(i)
				for (int i2 = 0; i2 < gameObjects.at(i)->Components.size(); i2++)
				{
					// find if there is a component T
					std::shared_ptr<T> dpCast = std::dynamic_pointer_cast<T>(gameObjects.at(i)->Components.at(i2));

					if (dpCast)
					{
						// if there is push back the game object it belongs to
						_rtn.push_back(gameObjects.at(i));
					}
				}
			}
			if(_rtn.empty()) throw rend::Exception("Failed to find specified game objects with component");	// Something is wrong with using goodengine::exception, maybe because they use the same file names?
			return 0;
		}



		void run();

	private:
		SDL_Window *window;
		std::weak_ptr<Core> self;

		//float deltaTime;
		std::shared_ptr<Enviroment> enviroment;

		SDL_GLContext glContext;

		// Are these pointers okay?
		ALCdevice* audioDevice;
		ALCcontext* audioContext;

		std::shared_ptr<rend::Context> context;
		//std::shared_ptr<rend::Shader> shader;

		friend class goodengine::GameObject;
		std::vector<std::shared_ptr<GameObject>> gameObjects;

		std::shared_ptr<Resources> resources;
		std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<Mouse> mouse;
		//screen
		//running

		bool quit;
	};

}