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

	// GUI
	guiTexture = getCore()->getResources()->load<Texture>("share/image1.png");

	// Camera
	go3 = getCore()->addGameObject();
	go3->getComponent<Transform>()->setPosition(glm::vec3(0.0f, 0.0f, 10.0f));
	shared<Camera> cam1 = go3->addComponent<Camera>();
	getCore()->setActiveCam(cam1);

}
void TestScene::onTick()
{
	if (getKeyboard()->getKey(SDLK_w))
	{
		glm::vec3 camPos = go3->getComponent<Transform>()->getPosition();
		camPos.z -= 0.005;
		go3->getComponent<Transform>()->setPosition(camPos);
	}
	else if (getKeyboard()->getKey(SDLK_s))
	{
		glm::vec3 camPos = go3->getComponent<Transform>()->getPosition();
		camPos.z += 0.005;
		go3->getComponent<Transform>()->setPosition(camPos);
	}
	if (getKeyboard()->getKey(SDLK_a))
	{
		glm::vec3 camPos = go3->getComponent<Transform>()->getPosition();
		camPos.x -= 0.005;
		go3->getComponent<Transform>()->setPosition(camPos);
	}
	else if (getKeyboard()->getKey(SDLK_d))
	{
		glm::vec3 camPos = go3->getComponent<Transform>()->getPosition();
		camPos.x += 0.005;
		go3->getComponent<Transform>()->setPosition(camPos);
	}
	if (getKeyboard()->getKey(SDLK_q))
	{
		glm::vec3 camPos = go3->getComponent<Transform>()->getPosition();
		camPos.y -= 0.005;
		go3->getComponent<Transform>()->setPosition(camPos);
	}
	else if (getKeyboard()->getKey(SDLK_e))
	{
		glm::vec3 camPos = go3->getComponent<Transform>()->getPosition();
		camPos.y += 0.005;
		go3->getComponent<Transform>()->setPosition(camPos);
	}

	if (getKeyboard()->getKey(SDLK_j))
	{
		glm::vec3 camRot = go3->getComponent<Transform>()->getRotation();
		camRot.y -= 0.005;
		go3->getComponent<Transform>()->setRotation(camRot);
	}
	else if (getKeyboard()->getKey(SDLK_l))
	{
		glm::vec3 camRot = go3->getComponent<Transform>()->getRotation();
		camRot.y += 0.005;
		go3->getComponent<Transform>()->setRotation(camRot);
	}

	if (getMouse()->getMouseButton(SDL_BUTTON_LEFT))
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

	if (getKeyboard()->getKey(SDLK_SPACE))
	{
		//getCore()->setActiveCam(nullptr);
	}

	// Spin
	glm::vec3 rot = go2->getComponent<Transform>()->getRotation();
	rot.y += 0.05;
	go2->getComponent<Transform>()->setRotation(rot);

	//glm::vec2 a = getMouse()->getMousePosition();
	//std::cout << "X = " << a.x << " Y = " << a.y << std::endl;
}
void TestScene::onDisplay()
{
	//std::cout << "DISPLAY" << std::endl;
}
void TestScene::onGui()
{
	getCore()->getGui()->texture(glm::vec4(10, 10, 100, 100), guiTexture);
}