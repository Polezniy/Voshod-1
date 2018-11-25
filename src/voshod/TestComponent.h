#pragma once

#include "Component.h"

namespace voshod
{
	class TestComponent : public Component
	{
	private:
		void onTick();
	};
}