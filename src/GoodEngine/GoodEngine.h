#pragma once
#ifndef GOODENGINE_GOODENGINE_H
#define GOODENGINE_GOODENGINE_H

#include "Core.h"
#include "Enviroment.h"
#include "GameObject.h"
#include "Transform.h"
#include "Component.h"
#include "Resources.h"
#include "Resource.h"
#include "Exception.h"
#include "MeshRenderer.h"
#include "Mesh.h"
#include "Texture.h"
#include "Gui.h"
#include "AudioSource.h"
#include "Audio.h"
#include "Keyboard.h"
#include "Mouse.h"
#include "BoxCollider.h"
#include "Camera.h"

#include <sr1/memory>

#define shared std::shared_ptr
#define weak std::weak_ptr

#endif

//	This is the meta file, it includes and defines everything so that the user does not have to.