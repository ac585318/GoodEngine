#include "Core.h"
#include "GameObject.h"
#include "Transform.h"
#include "Resources.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "Enviroment.h"

namespace goodengine {

	Core::~Core()
	{
		SDL_DestroyWindow(window);
		SDL_Quit();

		alcMakeContextCurrent(NULL);
		alcDestroyContext(audioContext);	// The lecture slides do this twice?
		alcDestroyContext(audioContext);
		alcCloseDevice(audioDevice);
	}

	std::shared_ptr<Core> Core::initialize()
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>();
		rtn->self = rtn;

		// Initialize SDL and window
		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}
		rtn->window = SDL_CreateWindow("GoodEngine Window",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		rtn->glContext = SDL_GL_CreateContext(rtn->window);

		if (!rtn->glContext)
		{
			throw std::exception("Failed to create OpenGL context");
		}
		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		// Initialize Enviroment
		rtn->enviroment = std::make_shared<Enviroment>();

		// Initialize rend
		rtn->context = rend::Context::initialize();

		// Initialize OpenAL / audio system
		rtn->audioDevice = alcOpenDevice(NULL);

		if (rtn->audioDevice == NULL)
		{
			throw std::exception();
		}

		rtn->audioContext = alcCreateContext(rtn->audioDevice, NULL);

		if (rtn->audioContext == NULL)
		{
			alcCloseDevice(rtn->audioDevice);
			throw std::exception();
		}
		// Set as current audio context
		if (!alcMakeContextCurrent(rtn->audioContext))
		{
			alcDestroyContext(rtn->audioContext);
			alcCloseDevice(rtn->audioDevice);
			throw std::exception();
		}

		// Initialize Resources class
		rtn->resources = std::make_shared<Resources>();
		rtn->resources->context = rtn->context;
		rtn->resources->core = rtn;
		
		// Initialize Keyboard and Mouse class
		rtn->keyboard = std::make_shared<Keyboard>();
		rtn->mouse = std::make_shared<Mouse>();

		rtn->quit = false;

		return rtn;
	}

	std::shared_ptr<GameObject> Core::addGameObject()
	{
		std::shared_ptr<GameObject> rtn = std::make_shared<GameObject>();

		rtn->core = self;
		rtn->self = rtn;

		rtn->addComponent<Transform>();

		gameObjects.push_back(rtn);

		return rtn;
	}

	void Core::run()
	{
		float lastTime = SDL_GetTicks();
		float time, diff;
		float idealTime = 1.0f / 60.0f;
		bool wasPressed, wasMousePressed = false;

		while (!quit)
		{
			time = SDL_GetTicks();
			diff = time - lastTime;

			enviroment->deltaTime = diff / 1000.0f;
			lastTime = time;

			// SDL generally runs at 60fps anyway
			//if (idealTime > enviroment->deltaTime)
			//{
				// Sleep off remaining time
			//	SDL_Delay((idealTime - enviroment->deltaTime) * 1000.0f);
			//}

				// SHOULD MOVE THIS TIME STUFF INTO ANOTHER CLASS - TODO
			

			// Clear pressed and released key vectors
			keyboard->keysPressed.clear();
			keyboard->keysReleased.clear();
			mouse->mouseButtonsPressed.clear();
			mouse->mouseButtonsReleased.clear();
			// Might be set back to true if key is held
			wasPressed = false;
			wasMousePressed = false;

			SDL_Event event = { 0 };

			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					quit = true;
				}
				// Keyboard Input
				// Could break these down into functions so flags and repetitive code isn't needed
				if (event.type == SDL_KEYDOWN)
				{
					for (int i = 0; i < keyboard->keys.size(); i++)
					{
						if (keyboard->keys.at(i) == event.key.keysym.sym) wasPressed = true;
					}
					if (!wasPressed)
					{
						keyboard->keysPressed.push_back(event.key.keysym.sym);
						keyboard->keys.push_back(event.key.keysym.sym);
					}
				}
				if (event.type == SDL_KEYUP)
				{
					for (int i = 0; i < keyboard->keys.size(); i++)
					{
						if (keyboard->keys.at(i) == event.key.keysym.sym) keyboard->keys.erase(keyboard->keys.begin() + i);
					}
					keyboard->keysReleased.push_back(event.key.keysym.sym);
				}
				// Mouse Input
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					for (int i = 0; i < mouse->mouseButtons.size(); i++)
					{
						if (mouse->mouseButtons.at(i) == event.button.button) wasMousePressed = true;
					}
					if (!wasMousePressed)
					{
						mouse->mouseButtonsPressed.push_back(event.button.button);
						mouse->mouseButtons.push_back(event.button.button);
					}
				}
				if (event.type == SDL_MOUSEBUTTONUP)
				{
					for (int i = 0; i < mouse->mouseButtons.size(); i++)
					{
						if (mouse->mouseButtons.at(i) == event.button.button) mouse->mouseButtons.erase(mouse->mouseButtons.begin() + i);
					}
					mouse->mouseButtonsReleased.push_back(event.button.button);
				}
				// Update the mouse's position as it moves
				if (event.type == SDL_MOUSEMOTION)
				{
					mouse->mouseX = event.motion.x;
					mouse->mouseY = event.motion.y;
				}
			}

			//Go through gameObjects and call their tick functions
			for (size_t i = 0; i < gameObjects.size(); i++)
			{
				gameObjects.at(i)->tick();
			}

			// Clear screen
			glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

			for (size_t i = 0; i < gameObjects.size(); i++)
			{
				gameObjects.at(i)->display();
			}

			SDL_GL_SwapWindow(window);
		}
	}

}