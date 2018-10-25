#include "Entity.h"

namespace voshod
{

	/*std::shared_ptr<Core> Entity::getCore()
	{
		return core.lock();
	}*/
	
	void Entity::tick()
	{
		for (auto it = components.begin();
			it != components.end(); it++)
		{
			if (!(*it)->began)
			{
				(*it)->onBegin();
				(*it)->began = true;
			}

			(*it)->onTick();
		}
	}

	void Entity::display()
	{
		for (auto it = components.begin();
			it != components.end(); it++)
		{
			(*it)->onDisplay();
		}
	}

}