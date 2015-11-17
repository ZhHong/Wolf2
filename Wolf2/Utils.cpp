#include "Utils.h"
#include <iostream>

#define BG_VALUE 10001

int Utils::bgval = 0;
float Utils::sqr_l = 5.0f;
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

double Utils::random(){
	
	return rand();
}

double Utils::random(int b, int e){
	
	return (b + (e - b)*rand() / (RAND_MAX + 1.0));
}

std::string Utils::getStateString(int state){
	//state 1 run/alive 0 die 2 hunte 3 runaway 4 call helip 5 call danger
	std::string temp = "";
	switch (state)
	{
	case 0:
		temp = "die";
		break;
	case 1:
		temp = "move";
		break;
	case 2:
		temp = "hunt";
		break;
	case 3:
		temp = "escape";
		break;
	case 4:
		temp = "food";
		break;
	case 5:
		temp = "danger";
		break;
	default:
		break;
	}
	return temp;
}