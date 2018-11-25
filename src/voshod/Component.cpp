#include "Component.h"
#include <iostream>

namespace voshod // To avoid collision with other libraries
{
	Component::~Component(){ }
	void Component::onTick() { }
	void Component::onBegin() { }
	void Component::onInit() { }
	void Component::onDisplay() { }

}