#include <GoodEngine/GoodEngine.h>

using namespace goodengine;

class TestScene : public Component
{
public:
	void onInit();
	void onTick();
	void onDisplay();
	void onGui();

	float deltaTime;

	shared<Camera> cam1;
	shared<GameObject> skybox, table, cube1, cube2, cube3, strawberry;
	shared<Texture> guiStaminaTexture, guiHealthTexture, guiWinTexture;

	shared<GameObject> player;
	float stamina;
	int health;

	bool winState;
};