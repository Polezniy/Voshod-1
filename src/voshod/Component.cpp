#include "Component.h"
#include <iostream>

namespace voshod
{
	Component::~Component(){ }
	void Component::onTick() { }
	void Component::onBegin() { }
	void Component::onInit() { }
	void Component::onDisplay() { }
}