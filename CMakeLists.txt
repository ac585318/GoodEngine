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
)

add_executable(sandbox
  src/sandbox/main.cpp
  src/sandbox/TestScene.h
)
target_link_libraries(sandbox GoodEngine)