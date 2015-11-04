#include "Animal.h"
#include <iostream>

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