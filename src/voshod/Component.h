#pragma once
#ifndef VOSHOD_COMPONENT_H
#define VOSHOD_COMPONENT_H

#include <memory>

namespace voshod // To avoid collision with other libraries
{
	class Entity; // Forward declare
	class Core; // Forward declare

	class Component
	{
		friend class Entity;

	public:
		virtual ~Component();
		std::shared_ptr<Core> getCore();
		std::shared_ptr<Entity> getEntity();

	private:
		std::weak_ptr<Entity> entity;
		bool began;

		virtual void onInit();
		virtual void onBegin();
		virtual void onTick();
		virtual void onDisplay();

	};

}
#endif