#include <memory>
#include <vector>

class Entity;

class Core
{
private:
  // entities
  std::vector<std::shared_ptr<Entity> > entities
public:
  void start();
  //void stop();
  std::shared_ptr<Entity> addEntity();			
};