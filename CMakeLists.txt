cmake_minimum_required(VERSION 2.6)
project(GOODENGINE)

add_library(GoodEngine
  src/GoodEngine/Core.cpp
)

add_executable(sandbox
  src/sandbox/main.cpp
)
target_link_libraries(sandbox GoodEngine)