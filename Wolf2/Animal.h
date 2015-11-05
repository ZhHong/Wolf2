#ifndef _ANIMALH_
#define _ANIMALH_
#include "Feature.h"
#include "CmdInfo.h"

class Animal:public Feature
{
public:
	Animal();
	~Animal();
	int id;
	int state;
	int speed;
	int angel;

	int current_time = 0;

	void move();
	void run();
	void eat();
	void callHelp();
	void callTogether();

	void mainloop();

	void waitForCmd(cmdinfo cmd);
};
#endif

