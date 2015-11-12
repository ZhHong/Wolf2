#ifndef _WORLDH_
#define _WORLDH_
#include <vector>
class World
{
public:
	~World();

	int weight;
	int height;
	static World * getInstance();
	std::vector<int> getRandomPoint();
private:
	World();
	static World * instance;
	static std::vector<std::vector<int>> pointvec;



};
#endif

