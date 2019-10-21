#include <memory>
#include <vector>

namespace goodengine {

	class GameObject;

	class Core
	{
	public:
		static std::shared_ptr<Core> initialize();
		std::shared_ptr<GameObject> addGameObject();
		
		void run();

	protected:
		friend class goodengine::GameObject;

		std::vector<std::shared_ptr<GameObject>> GameObjects;
	};

}