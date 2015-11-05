#include "Utils.h"
#include <iostream>

Utils::Utils()
{
}


Utils::~Utils()
{
}

void  Utils::print(int num){
	std::cout << num << std::endl;
}

void Utils::print(std::string str){
	std::cout << str << std::endl;
}