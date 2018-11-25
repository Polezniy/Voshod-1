#include <SDL2/SDL.h>

#include <memory>
#include <vector>

namespace voshod // To avoid collision with other libraries 
{
	class Entity; // Forward declare

	class Core
	{
	public:

		static std::shared_ptr<Core> initialize();
		std::shared_ptr<Entity> addEntity();

		void start();
		void stop();
	
	private:

		bool running;

		std::vector<std::shared_ptr<Entity> > entities; // Storing a number of entities in Core
		std::weak_ptr<Core> self;

		SDL_Window *window;

	};

}