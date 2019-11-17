#include "Core.h"
#include "GameObject.h"

namespace goodengine {

	Core::~Core()
	{
		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;

		// initialize SDL and window
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}
		rtn->window = SDL_CreateWindow("GoodEngine Window",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		//											Change these throws?
		if (!SDL_GL_CreateContext(rtn->window))
		{
			throw std::exception();
		
		}
		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		rtn->quit = false;

		return rtn;
	}

	std::shared_ptr<GameObject> Core::addGameObject()
	{
		std::shared_ptr<GameObject> rtn = std::make_shared<GameObject>();

		rtn->core = self;
		rtn->self = rtn;

		GameObjects.push_back(rtn);

		return rtn;
	}

	void Core::run()
	{
		while (!quit)
		{
			//move this into core and include SDL
			SDL_Event event = { 0 };

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					quit = true;
				}
			}

			//Go through GameObjects and call their tick functions
			for (size_t i = 0; i < GameObjects.size(); i++)
			{
				GameObjects.at(i)->tick();
			}
			for (size_t i = 0; i < GameObjects.size(); i++)
			{
				GameObjects.at(i)->display();
			}

			SDL_GL_SwapWindow(window);
		}
	}

}