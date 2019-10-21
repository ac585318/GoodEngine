#include <iostream>
#include <memory>

#include <GoodEngine/GoodEngine.h>

#include "TestScene.h"

using namespace goodengine;

int main()
{
	// Initialize our engine
	shared<Core> core = Core::initialize();

	// Create a single in-game object
	shared<GameObject> go = core->addGameObject();

	// Add a very simple component to it
	weak<TestScene> testScreen = go->addComponent<TestScene>();

	// Start the engine’s main loop
	core->run();

	return 0;
}