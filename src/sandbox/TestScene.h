#include <GoodEngine/Component.h>

#include <iostream>

using namespace goodengine;

class TestScene : public Component
{
public:
	void onTick()
	{
		std::cout << "TICK TestScene" << std::endl;
	}
};