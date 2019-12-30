
namespace goodengine {

	class Enviroment
	{
	public:
		float getDeltaTime() { return deltaTime; }
	private:
		friend class Core;
		float deltaTime;
	};

}