#include "Utils.h"
#include <iostream>

#define BG_VALUE 10001

int Utils::bgval = 0;
float Utils::sqr_l = 1.0f;
float Utils::wind_w = 800;
float Utils::wind_h = 600;


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

int Utils::getSerNum(){
	if (Utils::bgval == 0){
		Utils::bgval = BG_VALUE;
	}
	else{
		Utils::bgval += 1;
	}
	return Utils::bgval;
}