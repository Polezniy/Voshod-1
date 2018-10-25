#include <SDL2/SDL.h>

#include <memory>
#include <vector>

namespace voshod
{
	//class Entity;

	class Core
	{
	public:

		//static std::shared_ptr<Core> initialize();

		void start();
		//void stop();
		//std::shared_ptr<Entity> addEntity();

	private:

		bool running;
		std::vector<std::shared_ptr<Entity> > entities; // Storing a number of entities in Core
		std::weak_ptr<Core> self;

		SDL_Window *window;

	};

}