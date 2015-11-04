#ifndef _ANIMALH_
#define _ANIMALH_
#include "Feature.h"
class Animal:public Feature
{
public:
	Animal();
	~Animal();

	int speed;
	int angel;

	void move();
	void run();
	void eat();
	void callHelp();
	void callTogether();
};
#endif

