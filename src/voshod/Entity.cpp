#include "Entity.h"
#include "Component.h"

void Entity::tick()
{
  for(auto it = components.begin(); it != components.end(); it++)
  {
    (*it)->onTick();
  }
}