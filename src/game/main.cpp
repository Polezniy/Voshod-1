#include <iostream>
#include <SDL2/SDL.h>
//#include <GL/eglew.h>
#include <exception>
#include <voshod/voshod.h>  //engine

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class Player : public Component
{
public:
   void onTick()
   {
     std::cout << "Hello World" << std::endl;
   }
};

int main(int argc, char *argv[])
{
  std::shared_ptr<Core> core = std::make_shared<Core>();

  std::shared_ptr<Entity> player = core->addEntity();
  player->addComponent<Player>(0);

  core->start();

  if(SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    throw std::exception();
  }

  SDL_Window *window = SDL_CreateWindow("Triangle",
    SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
    WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);

  bool quit = false;

  while(!quit)
  {
    SDL_Event event = {0};

    while(SDL_PollEvent(&event))
    {
      if(event.type == SDL_QUIT)
      {
        quit = true;
      }
    }
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}
