#include <GoodEngine/GoodEngine.h>

using namespace goodengine;

class TestScene : public Component
{
public:
	void onInit();
	void onBegin();
	void onTick();
	void onDisplay();

	shared<GameObject> go, go2;
};