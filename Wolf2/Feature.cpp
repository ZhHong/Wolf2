#include "Feature.h"
#include <iostream>
#include <time.h>
#include <math.h>
#include "Utils.h"

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
	}
}


void Feature::move(){
	Feature::x += int(cos(Feature::angel));
	Feature::y += int(sin(Feature::angel));
	Utils::print("featue type <" + std::to_string(Feature::type) + "> feature id <" + std::to_string(Feature::id) + "> move------------------------");
}

void Feature::run(){

}

void Feature::eat(){

}

void Feature::callHelp(){

}

void Feature::callTogether(){

}
