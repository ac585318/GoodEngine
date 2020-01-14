cmake_minimum_required(VERSION 2.6)
project(GOODENGINE)

include_directories(src)

add_library(GoodEngine
  src/GoodEngine/GoodEngine.h
  src/GoodEngine/Core.cpp
  src/GoodEngine/Core.h
  src/GoodEngine/GameObject.cpp
  src/GoodEngine/GameObject.h
  src/GoodEngine/Component.cpp
  src/GoodEngine/Component.h
  src/GoodEngine/Exception.cpp
  src/GoodEngine/Exception.h
  src/GoodEngine/Transform.cpp
  src/GoodEngine/Transform.h
  src/GoodEngine/MeshRenderer.cpp
  src/GoodEngine/MeshRenderer.h
  src/GoodEngine/Resources.cpp
  src/GoodEngine/Resources.h
  src/GoodEngine/Resource.cpp
  src/GoodEngine/Resource.h
  src/GoodEngine/Mesh.cpp
  src/GoodEngine/Mesh.h
  src/GoodEngine/Texture.cpp
  src/GoodEngine/Texture.h
  src/GoodEngine/Audio.cpp
  src/GoodEngine/Audio.h
  src/GoodEngine/AudioSource.cpp
  src/GoodEngine/AudioSource.h
  src/GoodEngine/Keyboard.cpp
  src/GoodEngine/Keyboard.h
  src/GoodEngine/Mouse.cpp
  src/GoodEngine/Mouse.h
  src/GoodEngine/Enviroment.cpp
  src/GoodEngine/Enviroment.h
  src/GoodEngine/BoxCollider.cpp
  src/GoodEngine/BoxCollider.h
  src/GoodEngine/Gui.cpp
  src/GoodEngine/Gui.h
  src/GoodEngine/Camera.cpp
  src/GoodEngine/Camera.h
)
target_link_libraries(GoodEngine SDL2 OpenAL32 rend)

add_library(rend
  src/rend/Exception.cpp
  src/rend/Context.cpp
  src/rend/Texture.cpp
  src/rend/RenderTexture.cpp
  src/rend/Shader.cpp
  src/rend/Buffer.cpp
  src/rend/Mesh.cpp
  src/rend/Util.cpp
)
if(MSVC)
  target_link_libraries(rend glew32 opengl32)
else()
  target_link_libraries(rend GLEW GL)
endif()

add_executable(sandbox
  src/sandbox/main.cpp
  src/sandbox/TestScene.h
  src/sandbox/TestScene.cpp
)
target_link_libraries(sandbox GoodEngine)

add_executable(rotate
  src/rotate/main.cpp
)
target_link_libraries(rotate rend SDL2)