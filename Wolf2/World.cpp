#include <time.h>
#include "World.h"
#include "Utils.h"

World * World::instance = nullptr;
std::vector<std::vector<int>> World::pointvec = std::vector<std::vector<int>>();


World::World()
{
	World::weight = int(Utils::wind_w);
	World::height = int(Utils::wind_h);
	//set random seed to time
	srand(unsigned(time(0)));
}


World::~World()
{
	delete World::instance;
}


World * World::getInstance(){
	if (World::instance == nullptr){
		World::instance = new World();
	}
	return instance;
}

//get random point of the screen
std::vector<int> World::getRandomPoint(){
	int x=int(Utils::random(-World::weight/8, World::weight/8));
	int y = int(Utils::random(-World::height/8, World::height/8));
	int angel = int(Utils::random(0, 360));
	std::vector<int> temp = {x,y,angel};
	return temp;
}