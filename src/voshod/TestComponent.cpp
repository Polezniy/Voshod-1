#include "TestComponent.h"
#include <iostream>

namespace voshod
{
	void TestComponent::onTick()
	{
		std::cout << "tickz\n";
	}
}