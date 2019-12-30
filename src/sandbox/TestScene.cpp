#include "TestScene.h"

void TestScene::onInit()
{
	//std::cout << "INIT" << std::endl;

	// go
	go = getCore()->addGameObject();
	go->getComponent<Transform>()->setPosition(glm::vec3(-2, -4, 0));

	go->addComponent<BoxCollider>();
	go->getComponent<BoxCollider>()->setSize(glm::vec3(1, 1, 1));

	shared<MeshRenderer> mr = go->addComponent<MeshRenderer>();
	shared<Mesh> mesh = getCore()->getResources()->load<Mesh>("share/rend/samples/box/box.obj");
	mr->setMesh(mesh);
	shared<Texture> texture = getCore()->getResources()->load<Texture>("share/rend/samples/box/box.png");
	mr->setTexture("u_Texture", texture);
	

	// go2
	go2 = getCore()->addGameObject();
	go2->getComponent<Transform>()->setPosition(glm::vec3(2, -4, 0));

	go2->addComponent<BoxCollider>();
	go2->getComponent<BoxCollider>()->setSize(glm::vec3(1, 1, 1));

	shared<MeshRenderer> mr2 = go2->addComponent<MeshRenderer>();
	shared<Mesh> mesh2 = getCore()->getResources()->load<Mesh>("share/rend/samples/box/box.obj");
	mr2->setMesh(mesh2);
	shared<Texture> texture2 = getCore()->getResources()->load<Texture>("share/rend/samples/box/box.png");
	mr2->setTexture("u_Texture", texture2);

}
void TestScene::onBegin()
{
	//std::cout << "BEGIN" << std::endl;
}
void TestScene::onTick()
{
	if (getKeyboard()->getKey(SDLK_a))
	{
		std::cout << "A HELD!" << std::endl;
	}
	else if (getKeyboard()->getKeyDown(SDLK_s))
	{
		std::cout << "S DOWN!" << std::endl;
	}
	else if (getKeyboard()->getKeyUp(SDLK_d))
	{
		std::cout << "D UP!" << std::endl;
	}
	else if (getMouse()->getMouseButton(SDL_BUTTON_LEFT))
	{
		std::cout << "ML HELD!" << std::endl;
	}
	else if (getMouse()->getMouseButtonDown(SDL_BUTTON_MIDDLE))
	{
		std::cout << "MM DOWN!" << std::endl;
	}
	else if (getMouse()->getMouseButtonUp(SDL_BUTTON_RIGHT))
	{
		std::cout << "MR UP!" << std::endl;
	}

	if (getKeyboard()->getKey(SDLK_LEFT))
	{
		//																		MAKE A FUNCTION LIKE "movePosition()"
		glm::vec3 pos = go->getComponent<Transform>()->getPosition();
		pos.x -= 0.005;
		go->getComponent<Transform>()->setPosition(pos);
	}
	if (getKeyboard()->getKey(SDLK_RIGHT))
	{
		glm::vec3 pos = go->getComponent<Transform>()->getPosition();
		pos.x += 0.005;
		go->getComponent<Transform>()->setPosition(pos);
	}
	if (getKeyboard()->getKey(SDLK_UP))
	{
		glm::vec3 pos = go->getComponent<Transform>()->getPosition();
		pos.y += 0.005;
		go->getComponent<Transform>()->setPosition(pos);
	}
	if (getKeyboard()->getKey(SDLK_DOWN))
	{
		glm::vec3 pos = go->getComponent<Transform>()->getPosition();
		pos.y -= 0.005;
		go->getComponent<Transform>()->setPosition(pos);
	}

	//glm::vec2 a = getMouse()->getMousePosition();
	//std::cout << "X = " << a.x << " Y = " << a.y << std::endl;

}
void TestScene::onDisplay()
{
	//std::cout << "DISPLAY" << std::endl;
}