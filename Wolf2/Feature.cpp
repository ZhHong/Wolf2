#include "Feature.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include "Utils.h"
#include <thread>
#include "DataManager.h"

#define random(x) (rand()%x)
Feature::Feature()
{
}


Feature::~Feature()
{
}
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
			Feature::move();
			Feature::checkMsgBox();
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
	Feature::x += int(cos(Feature::angel));
	Feature::y += int(sin(Feature::angel));
	Utils::print("featue type <" + std::to_string(Feature::type) + "> feature id <" + std::to_string(Feature::id) + "> move------------------------");
	//std::vector<std::string> vec;
	//srand((int)time(0));
	//Utils::print(vec[int(random(5))]);
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
