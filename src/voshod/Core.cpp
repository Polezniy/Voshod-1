#include "Core.h"
#include "Entity.h"

#include <GL/glew.h>

#include <iostream>

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 600

namespace voshod // To avoid collision with other libraries 
{
	std::shared_ptr<Core> Core::initialize() // Initializing SDL
	{
		std::shared_ptr<Core> rtn = std::make_shared<Core>(); // Creating an instance of a Core
		rtn->running = false;
		rtn->self = rtn;

		if (SDL_Init(SDL_INIT_VIDEO) < 0)
		{
			throw std::exception();
		}

		rtn->window = SDL_CreateWindow("My game",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

		if (!SDL_GL_CreateContext(rtn->window))
		{
			throw std::exception();
		}

		if (glewInit() != GLEW_OK)
		{
			throw std::exception();
		}

		return rtn;
	}

	void Core::start()
	{
		running = true;

		while (running)
		{
			SDL_Event event = { 0 };
			
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					running = false;
				}
			}

			for (auto it = entities.begin(); it != entities.end(); it++) // Go through each entity and call a "Tick"
			{
				(*it)->tick();
			}

			for (auto it = entities.begin(); it != entities.end(); it++) // Go through each entity and call a "Display"
			{
				(*it)->display();
			}

			glClearColor(1.0f, 0.0f, 0.0f, 1.0f); // Setting OpenGL clear colour to red
			glClear(GL_COLOR_BUFFER_BIT); // Clearing the screen

			SDL_GL_SwapWindow(window);

			addEntity();
		}

		SDL_DestroyWindow(window);
		SDL_Quit();
	}

	void Core::stop()
	{
		running = false;
	}

	std::shared_ptr<Entity> Core::addEntity()
	{
		std::shared_ptr<Entity> rtn = std::make_shared<Entity>(); // Creating an instance of an Entity
		entities.push_back(rtn); // Adding it to the list of Entities
		rtn->self = rtn;
		rtn->core = self;

		return rtn;
	}
}