#include "Feature.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include "Utils.h"
#include <thread>
#include "DataManager.h"
#include "World.h"

#define random(x) (rand()%x)
Feature::Feature()
{
	World* worldin = World::getInstance();
	std::vector<int> val=worldin->getRandomPoint();
	Feature::x = val[0];
	Feature::y = val[1];
	Feature::angel = val[2];
	
}


Feature::~Feature()
{
}
//two way to send msg/recivemsg
//1 send msg to all
//2 manager send msg
void Feature::sendMsgToObj(Feature f, cmdinfo msg){
	f.reviceMsg(f, msg);
}

void Feature::reviceMsg(Feature f, cmdinfo msg){
	Feature::msgboxs.push_back(msg);
}

void Feature::checkMsgBox(){
	auto it = Feature::msgboxs.begin();
	for (it; it != Feature::msgboxs.end(); it++){
		Utils::print(it->type);
		Utils::print(it->actionId);
		Utils::print(it->modelId);
		Utils::print(it->data);
	}
}

void Feature::mainloop(){
	while (true)
	{
		int now = int(time(0));
		if (Feature::current_time + 1<now){
			Feature::current_time = now;
			//std::cout << Animal::id <<"wait for cmd" << std::endl;
			Feature::checkMsgBox();
			Feature::move();
		}
		//sleep thread 
		std::chrono::milliseconds timespan(10);
		std::this_thread::sleep_for(timespan);
		//second ways
		//#ifdef _WIN32
		//#include <windows.h>
		//
		//		void sleep(unsigned milliseconds)
		//		{
		//			Sleep(milliseconds);
		//		}
		//#else
		//#include <unistd.h>
		//
		//		void sleep(unsigned milliseconds)
		//		{
		//			usleep(milliseconds * 1000); // takes microseconds
		//		}
		//#endif
	}
}


void Feature::move(){

	//todo add do not run out of window
	float tempx =float(Feature::x + int(cos(Feature::angel)*Feature::speed));
	float tempy =float(Feature::y + int(sin(Feature::angel)*Feature::speed));

	//x
	if (tempx<=0){
		Feature::angel = 180-Feature::angel;
	}
	if (tempx >= Utils::wind_w){
		Feature::angel = 180 -Feature::angel;
	}
	//y
	if (tempy < 0){
		Feature::angel =-angel;
	}
	if (tempy >= Utils::wind_h){
		Feature::angel =  - angel;
	}

	Feature::x += int(cos(Feature::angel)*Feature::speed);
	if (Feature::x<0){
		Feature::x = 0;
	}
	if (Feature::x > Utils::wind_w){
		Feature::x = int(Utils::wind_w);
	}
	Feature::y += int(sin(Feature::angel)*Feature::speed);
	if (Feature::y<0){
		Feature::y = 0;
	}
	if (Feature::y > Utils::wind_h){
		Feature::y = int(Utils::wind_h);
	}
}

void Feature::run(){
	Feature::x += 2*int(cos(Feature::angel));
	Feature::y += 2*int(sin(Feature::angel));
}

void Feature::eat(){
	auto dataManager = DataManager::getInstance();
	dataManager->featureEat(this);
}

void Feature::callHelp(){
	auto dataManager=DataManager::getInstance();
	dataManager->featureCallHelp(this);
}

void Feature::callTogether(){
	auto dataManager = DataManager::getInstance();
	dataManager->featureCallTogether(this);
}
