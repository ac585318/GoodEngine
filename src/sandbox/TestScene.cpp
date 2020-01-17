#include "TestScene.h"

void TestScene::onInit()
{
	winState = false;

	// Play a sound
	shared<GameObject> soundGO = getCore()->addGameObject();
	shared<AudioSource> soundEmitter = soundGO->addComponent<AudioSource>();
	shared<Audio> sound = getCore()->getResources()->load<Audio>("share/sounds/1up.ogg");
	soundEmitter->setAudio(sound);


	// Load GUI textures
	guiStaminaTexture = getCore()->getResources()->load<Texture>("share/images/image1.png");
	guiHealthTexture = getCore()->getResources()->load<Texture>("share/images/image2.png");
	guiWinTexture = getCore()->getResources()->load<Texture>("share/images/win.png");


	// Skybox
	skybox = getCore()->addGameObject();
	skybox->getComponent<Transform>()->setPosition(2.0f, -4.0f, 0.0f);

	shared<MeshRenderer> skyboxMR = skybox->addComponent<MeshRenderer>();
	shared<Mesh> skyboxM = getCore()->getResources()->load<Mesh>("share/skybox/skybox.obj");
	skyboxMR->setMesh(skyboxM);
	shared<Texture> skyboxTex = getCore()->getResources()->load<Texture>("share/skybox/skybox.png");
	skyboxMR->setTexture("u_Texture", skyboxTex);


	// Table
	table = getCore()->addGameObject();
	table->getComponent<Transform>()->setPosition(0.0f, -5.0f, 10.0f);

	shared<BoxCollider> table_BC = table->addComponent<BoxCollider>();
	table_BC->setSize(glm::vec3(10, 4, 5));
	table_BC->setOffset(glm::vec3(0, 0, 0));
	table_BC->isStaticCollider(true);

	shared<MeshRenderer> tableMR = table->addComponent<MeshRenderer>();
	shared<Mesh> tableM = getCore()->getResources()->load<Mesh>("share/table/tableL.obj");
	tableMR->setMesh(tableM);
	shared<Texture> tableTex = getCore()->getResources()->load<Texture>("share/table/Untitled.png");
	tableMR->setTexture("u_Texture", tableTex);


	// Cubes
	cube1 = getCore()->addGameObject();
	cube1->getComponent<Transform>()->setPosition(16., 0.3, 7.5);
	cube2 = getCore()->addGameObject();
	cube2->getComponent<Transform>()->setPosition(15., 0.3, -11.5);
	cube3 = getCore()->addGameObject();
	cube3->getComponent<Transform>()->setPosition(2., 4.5, -8.5);

	shared<BoxCollider> cube1_BC = cube1->addComponent<BoxCollider>();
	cube1_BC->setSize(glm::vec3(4, 1, 4));
	cube1_BC->setOffset(glm::vec3(0, -1.0, 0));
	cube1_BC->isStaticCollider(true);
	shared<BoxCollider> cube2_BC = cube2->addComponent<BoxCollider>();
	cube2_BC->setSize(glm::vec3(4, 1, 4));
	cube2_BC->setOffset(glm::vec3(0, -1.0, 0));
	cube2_BC->isStaticCollider(true);
	shared<BoxCollider> cube3_BC = cube3->addComponent<BoxCollider>();
	cube3_BC->setSize(glm::vec3(4, 1, 4));
	cube3_BC->setOffset(glm::vec3(0, -1.0, 0));
	cube3_BC->isStaticCollider(true);

	shared<MeshRenderer> cube1_MR = cube1->addComponent<MeshRenderer>();
	shared<MeshRenderer> cube2_MR = cube2->addComponent<MeshRenderer>();
	shared<MeshRenderer> cube3_MR = cube3->addComponent<MeshRenderer>();

	shared<Mesh> cubeM = getCore()->getResources()->load<Mesh>("share/floorTile/floorTile.obj");
	shared<Texture> cubeTex = getCore()->getResources()->load<Texture>("share/floorTile/floorTile.png");
	
	cube1_MR->setMesh(cubeM);
	cube2_MR->setMesh(cubeM);
	cube3_MR->setMesh(cubeM);
	cube1_MR->setTexture("u_Texture", cubeTex);
	cube2_MR->setTexture("u_Texture", cubeTex);
	cube3_MR->setTexture("u_Texture", cubeTex);


	// Strawberry!
	strawberry = getCore()->addGameObject();
	strawberry->getComponent<Transform>()->setPosition(2., 9.5, -8.5);
	shared<BoxCollider> strawberry_BC = strawberry->addComponent<BoxCollider>();

	strawberry_BC->setSize(glm::vec3(1, 1, 1));
	strawberry_BC->setOffset(glm::vec3(0, 0, 0));
	strawberry_BC->isStaticCollider(true);

	shared<MeshRenderer> strawberry_MR = strawberry->addComponent<MeshRenderer>();
	shared<Mesh> strawberry_M = getCore()->getResources()->load<Mesh>("share/Strawberry/strawberryL.obj");
	shared<Texture> strawberry_Tex = getCore()->getResources()->load<Texture>("share/Strawberry/strawberry.png");
	strawberry_MR->setMesh(strawberry_M);
	strawberry_MR->setTexture("u_Texture", strawberry_Tex);


	// Player
	player = getCore()->addGameObject();
	player->getComponent<Transform>()->setPosition(2.0f, 2.0f, 10.0f);
	shared<BoxCollider> charBox = player->addComponent<BoxCollider>();
	charBox->setSize(glm::vec3(0.8f, 1.4f, 1.0f));
	charBox->setOffset(glm::vec3(0.0f, 0.4f, 0.0f));
	charBox->setTriggerObject(strawberry_BC);								// Set strawberry as triggerObject
	shared<MeshRenderer> playerMR = player->addComponent<MeshRenderer>();
	shared<Mesh> playerM = getCore()->getResources()->load<Mesh>("share/aimaina/Aimaina.obj");
	shared<Texture> playerTex = getCore()->getResources()->load<Texture>("share/aimaina/Aimaina.png");
	playerMR->setMesh(playerM);
	playerMR->setTexture("u_Texture", playerTex);
	stamina = 100.0f;
	health = 3;


	// Camera
	shared<GameObject> camGO = getCore()->addGameObject();
	camGO->getComponent<Transform>()->setPosition(0.0f, 0.0f, 15.0f);
	cam1 = camGO->addComponent<Camera>();
	getCore()->setActiveCam(cam1);
}
void TestScene::onTick()
{
	deltaTime = getCore()->getEnviroment()->getDeltaTime();
	float moveSpeed = 5.0f * deltaTime;
	float turnSpeed = 180.0f * deltaTime;


	// Char control (tank controls)
	if (getKeyboard()->getKey(SDLK_w))
	{
		player->getComponent<Transform>()->movePosition(FORWARD, moveSpeed);
	}
	else if (getKeyboard()->getKey(SDLK_s))
	{
		player->getComponent<Transform>()->movePosition(BACK, moveSpeed);
	}
	if (getKeyboard()->getKey(SDLK_a))
	{
		player->getComponent<Transform>()->addRotation(glm::vec3(0, turnSpeed, 0));
	}
	if (getKeyboard()->getKey(SDLK_d))
	{
		player->getComponent<Transform>()->addRotation(glm::vec3(0, -turnSpeed, 0));
	}
	if ((getMouse()->getMouseButton(SDL_BUTTON_LEFT) || getKeyboard()->getKey(SDLK_SPACE)) && stamina > 0)	// Fly
	{
		stamina -= 100 * deltaTime;
		player->getComponent<Transform>()->movePosition(UP, moveSpeed*2);
	}
	else
	{
		stamina += 50 * deltaTime;
		if (stamina > 100) stamina = 100;
	}
	// Gravity hack, also deltaTime causes issues for BoxCollision if it's too high
	if (deltaTime > 0.1f)
		player->getComponent<Transform>()->movePosition(DOWN, 0.005f);
	else
		player->getComponent<Transform>()->movePosition(DOWN, moveSpeed);


	// Cam control
	if (getKeyboard()->getKey(SDLK_j))
	{
		cam1->getTransform()->addRotation(glm::vec3(0, 60.0 * deltaTime, 0));
	}
	if (getKeyboard()->getKey(SDLK_l))
	{
		cam1->getTransform()->addRotation(glm::vec3(0, -60.0 * deltaTime, 0));
	}
	if (getKeyboard()->getKey(SDLK_k))
	{
		cam1->getTransform()->setRotation(0, 0, 0);
	}


	// Damage player if they fall off stage
	if (player->getTransform()->getPosition().y <= -10.0f)
	{
		health--;
		if (health <= 0)
		{
			getCore()->quitGame(true);
		}
		// Reposition back on level
		player->getTransform()->setPosition(2.0f, 2.0f, 10.0f);
	}


	// Check if the player "got" the strawberry
	if (player->getComponent<BoxCollider>()->getTriggerHit())
	{
		// Since we don't have a GameObject delete funciton yet
		strawberry->getTransform()->setPosition(0, -100, 0);

		winState = true;
	}
}
void TestScene::onDisplay()
{
	glm::vec3 followPos = player->getTransform()->getPosition();
	followPos.y += 4;
	followPos.z += 11;
	cam1->getTransform()->setPosition(followPos);

	// Rotate skybox
	skybox->getComponent<Transform>()->addRotation(glm::vec3(0, 1.0f * deltaTime, 0));
}
void TestScene::onGui()
{
	// Stamina
	getCore()->getGui()->texture(glm::vec4(10, 10, stamina, 80), guiStaminaTexture);

	// Hearts
	for (int i = 0; i < health; i++)
	{
		getCore()->getGui()->texture(glm::vec4((getCore()->getScreenSize().x / 2) - 105 + i * 55, 10, 50, 50), guiHealthTexture);
	}

	if (winState)
	{
		getCore()->getGui()->texture(glm::vec4(getCore()->getScreenSize().x - 260, 10, 250, 250), guiWinTexture);
	}
}