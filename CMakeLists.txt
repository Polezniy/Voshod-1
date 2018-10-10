cmake_minimum_required(VERSION 2.6)
project(VOSHOD-1)

include_directories(
     contrib
     src
)

add_executable(game
  src/game/main.cpp
  src/game/TestScene.cpp
)

add_library(voshod
  src/voshod/Core.cpp
)

if(MSVC)
  include_directories(
  	  contrib/msvc-windows-x86/glew/include
	  contrib/msvc-windows-x86/SDL2/include
  )

link_directories(
   ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/glew/lib
   ${CMAKE_SOURCE_DIR}/contrib/msvc-windows-x86/SDL2/lib
)
endif()

if(MSVC)
 target_link_libraries(game
    SDL2.lib
    glew32.lib
)
endif()

target_link_libraries(game voshod)