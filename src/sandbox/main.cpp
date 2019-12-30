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
	shared<MeshRenderer> mr = go->addComponent<MeshRenderer>();

	shared<Mesh> mesh = core->getResources()->load<Mesh>("share/rend/samples/curuthers/curuthers.obj");

	mr->setMesh(mesh);

	// load texture here
	shared<Texture> texture = core->getResources()->load<Texture>("share/rend/samples/curuthers/Whiskers_diffuse.png");

	// set texture here
	mr->setTexture("u_Texture", texture);

	// Audio
	shared<AudioSource> soundEmitter = go->addComponent<AudioSource>();
	shared<Audio> sound = core->getResources()->load<Audio>("share/1up.ogg");
	soundEmitter->setAudio(sound);

	core->addGameObject()->addComponent<TestScene>();

	/*
	// go2
	shared<GameObject> go2 = core->addGameObject();
	go2->getComponent<Transform>()->setPosition(glm::vec3(-2, -4, 0));

	go2->addComponent<BoxCollider>();
	go2->getComponent<BoxCollider>()->setSize(glm::vec3(1, 1, 1));

	shared<MeshRenderer> mr2 = go2->addComponent<MeshRenderer>();
	shared<Mesh> mesh2 = core->getResources()->load<Mesh>("share/rend/samples/box/box.obj");
	mr2->setMesh(mesh2);
	shared<Texture> texture2 = core->getResources()->load<Texture>("share/rend/samples/box/box.png");
	mr2->setTexture("u_Texture", texture2);
	*/

	// Start the engine’s main loop
	core->run();

	return 0;
}