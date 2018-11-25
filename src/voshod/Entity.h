#include "Component.h"

#include <memory>
#include <vector>

#define ADDCOMPONENT \
  std::shared_ptr<T> rtn = std::make_shared<T>(); \
  rtn->entity = self; \
  rtn->began = false; \
  components.push_back(rtn);

namespace voshod // To avoid collision with other libraries 
{
	class Core; // Forward declare

	class Entity
	{

		friend class Core;

	public:

		void display();
		void tick();

		template <typename T>
		std::shared_ptr<T> getComponent()
		{
			for (size_t i = 0; i < components.size(); i++)
			{
				std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(components.at(i));

				if (tst)
				{
					return tst;
				}
			}

			throw std::exception();
		}

		template <typename T>
		std::shared_ptr<T> addComponent()
		{
			ADDCOMPONENT
				rtn->onInit();

			return rtn;
		}

		template <typename T, typename A>
		std::shared_ptr<T> addComponent(A a)
		{
			ADDCOMPONENT
				rtn->onInit(a);

			return rtn;
		}

		template <typename T, typename A, typename B>
		std::shared_ptr<T> addComponent(A a, B b)
		{
			ADDCOMPONENT
				rtn->onInit(a, b);

			return rtn;
		}


	private:

		std::vector<std::shared_ptr<Component> > components; // Storing a number of components in Entity
		std::weak_ptr<Entity> self;
		std::weak_ptr<Core> core;

	};
}