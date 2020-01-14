#include <GoodEngine/GoodEngine.h>

using namespace goodengine;

class TestScene : public Component
{
public:
	void onInit();
	void onTick();
	void onDisplay();
	void onGui();

	shared<GameObject> go, go2, go3;
	shared<Texture> guiTexture;
};