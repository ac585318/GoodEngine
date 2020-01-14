#include <memory>
#include <vector>

#include <SDL2/SDL.h>
#include <GL/glew.h>
#include <rend/rend.h>

#include <AL/al.h>
#include <AL/alc.h>

#include <exception>

namespace goodengine {

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 640

	class GameObject;
	class Resources;
	class Gui;
	class Keyboard;
	class Mouse;
	class Enviroment;
	class Camera;

	///
	/// The Core of the engine. It manages and updates the engine and most of its classes.
	/// Contains a list of all GameObject objects.
	///
	class Core
	{
	public:
		///
		/// \brief A destructor
		///
		~Core();

		///
		/// \brief Initializes and returns the Core object
		/// \return Shared pointer to the initialized Core
		///
		static std::shared_ptr<Core> initialize();
		// static makes this function more accessible to outside the engine (main.cpp)

		///
		/// \brief Add a new GameObject
		/// \return Shared pointer to the newly created GameObject
		///
		std::shared_ptr<GameObject> addGameObject();

		///
		/// \brief Returns all GameObject objects active in Core
		/// \return Vector of GameObject
		///
		std::vector<std::shared_ptr<GameObject>> getGameObjects() { return gameObjects; }

		///
		/// \brief Pushback GameObject objects with a specific Component into a vector
		///
		/// Pushback GameObjects, into the _rtn vector parameter,
		/// which have the Component as specified as return type T
		///
		/// \param _rtn a vector of GameObject for storing GameObjects
		/// \return 0 if successful
		///
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
			if (_rtn.empty()) throw rend::Exception("Failed to find specified game objects with component");	// Something is wrong with using goodengine::exception, maybe because they use the same file names?
			return 0;
		}

		///
		/// \brief Returns the Gui class
		///
		/// \return Shared pointer to Gui
		///
		std::shared_ptr<Gui> getGui() { return gui; }

		///
		/// \brief Returns the Resources class
		///
		/// Use this to access the Gui class and functions
		/// \return Shared pointer to Resources
		///
		std::shared_ptr<Resources> getResources() { return resources; }

		///
		/// \brief Returns the Keyboard class
		///
		/// Use this to access the Keyboard class and functions
		/// \return Shared pointer to Keyboard
		///
		std::shared_ptr<Keyboard> getKeyboard() { return keyboard; }

		///
		/// \brief Returns the Mouse class
		///
		/// Use this to access the Mouse class and functions
		/// \return Shared pointer to Mouse
		///
		std::shared_ptr<Mouse> getMouse() { return mouse; }

		///
		/// \brief Returns the screen size, width and height
		/// \return glm::vec2(window_width, window_height)
		///
		glm::vec2 getScreenSize() { return glm::vec2(WINDOW_WIDTH, WINDOW_HEIGHT); }

		///
		/// \brief Returns the Context class
		///
		/// Use this to access the underlying rend library Context class and functions
		/// \return Shared pointer to rend::Context
		///
		std::shared_ptr<rend::Context> getContext() { return context; }

		///
		/// \brief Set the active Camera which renders to the screen
		/// \param _cam the Camera to set as active
		///
		void setActiveCam(std::shared_ptr<Camera> _cam) { activeCam = _cam; }

		///
		/// \brief Get the active Camera which renders to the screen
		/// \return Shared pointer to active Camera. Returns nullptr if there is none
		///
		std::shared_ptr<Camera> getActiveCam();

		///
		/// \brief Run the Core / Good Engine
		///
		/// Use this is run the engine. This updates run-time only variables and classes,
		/// such as Enviroment, and loops through all GameObject objects active in Core
		///
		void run();

	private:
		std::weak_ptr<Core> self;
		std::shared_ptr<rend::Context> context;

		SDL_Window *window;
		SDL_GLContext glContext;
		ALCdevice* audioDevice;
		ALCcontext* audioContext;

		friend class goodengine::GameObject;
		std::vector<std::shared_ptr<GameObject>> gameObjects;

		std::weak_ptr<Camera> activeCam;
		std::shared_ptr<Gui> gui;
		std::shared_ptr<Enviroment> enviroment;
		std::shared_ptr<Resources> resources;
		std::shared_ptr<Keyboard> keyboard;
		std::shared_ptr<Mouse> mouse;

		bool quit;
	};

}