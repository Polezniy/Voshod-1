#include "Entity.h"

namespace voshod // To avoid collision with other libraries
{
	
	void Entity::tick()
	{
		for (auto it = components.begin(); it != components.end(); it++)
		{
			if (!(*it)->began) // Check if component is not active
			{
				(*it)->onBegin();
				(*it)->began = true; // Activate it
			}

			(*it)->onTick();
		}
	}

	void Entity::display()
	{
		for (auto it = components.begin(); it != components.end(); it++)
		{
			(*it)->onDisplay();
		}
	}

}