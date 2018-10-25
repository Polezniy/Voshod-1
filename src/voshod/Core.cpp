#include "Core.h"
#include "Entity.h"

namespace voshod
{
	void Core::start()
	{
		while (running)
		{
			for (auto it = entities.begin(); it != entities.end(); it++)
			{
				(*it)->tick();
			}
		}
	}
}