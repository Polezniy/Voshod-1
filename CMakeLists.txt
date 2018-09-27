cmake_minimum_required(VERSION 2.6)
project(VOSHOD-1)

add_executable(testGame
  src/testGame/main.cpp
  src/testGame/TestScene.cpp
)

add_library(testLib
  src/testLib/Entity.cpp
)

target_link_libraries(testGame testLib)