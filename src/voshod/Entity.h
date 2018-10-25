#include "Component.h"

#include <memory>
#include <vector>

namespace voshod
{

	class Entity
	{
	public:

		void display();
		void tick();

	private:

		std::vector<std::shared_ptr<Component> > components; // Storing a number of components in Entity

	};
}