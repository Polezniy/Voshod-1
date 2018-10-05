#include <memory>
#include <vector>

class Component;

class Entity
{
private: 
  std::vector<std::shared_ptr<Component> > components;

public:
  void tick();

  template <typename T>
  std::shared_ptr<T> addComponent()
  {
    std::shared_ptr<T> rtn = std::make_shared<T>();

    components.push_back(rtn);
    
    return rtn;
  }
};