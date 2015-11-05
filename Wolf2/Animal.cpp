#include "Animal.h"
#include <iostream>
#include <time.h>

Animal::Animal()
{
}


Animal::~Animal()
{
}

void Animal::move(){
	Animal::x += int(cos(Animal::angel));
	Animal::y += int(sin(Animal::angel));
	std::cout << "Animal type " << Animal::type << "   move-------------" << std::endl;
}

void Animal::run(){

}

void Animal::eat(){

}

void Animal::callHelp(){

}

void Animal::callTogether(){

}

void Animal::waitForCmd(cmdinfo cmd){
	std::cout << cmd.type << cmd.modelId << cmd.actionId << cmd.data << std::endl;
}

void Animal::mainloop(){
	while (true)
	{
		int now = int(time(0));
		if (Animal::current_time+1<now){
			Animal::current_time = now;
			std::cout << Animal::id <<"wait for cmd" << std::endl;
		}
	}
}