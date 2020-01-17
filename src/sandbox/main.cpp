#include <iostream>
#include <memory>

#include <GoodEngine/GoodEngine.h>

#include "TestScene.h"

using namespace goodengine;

int main()
{
	// Initialize our engine
	shared<Core> core = Core::initialize();

	core->addGameObject()->addComponent<TestScene>();

	// Start the engine’s main loop
	core->run();

	return 0;
}