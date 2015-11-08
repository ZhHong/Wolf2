#include <thread>
#include "DataManager.h"
#include "Utils.h"


DataManager* DataManager::instance = nullptr;
std::map<int, Feature> DataManager::featuremap = std::map<int, Feature>();

DataManager * DataManager::getInstance(){
	if (DataManager::instance = nullptr){
		instance = new DataManager();
	}
	return instance;
}

DataManager::DataManager()
{
}


DataManager::~DataManager()
{
}

std::map<int, Feature>::iterator DataManager::getFeature(int id){
	return  DataManager::featuremap.find(id);
}

void DataManager::addFeature(int id, Feature f){
	Utils::print("insert id====="+std::to_string(id));
	DataManager::instance->featuremap.insert(std::pair<int, Feature>(id, f));
}

void DataManager::removeFeature(int id){

}

void DataManager::initFeatrue(){
	int wolf_num = 10;
	int rb_num = 20;
	int carrot_num = 30;
	for (int i = 1; i <= carrot_num; i++){
		
		if (i <= wolf_num){
			//Rabbit rb = Rabbit(Utils::getSerNum());
			Wolf wf = Wolf(Utils::getSerNum());
			//DataManager::addFeature(rb.id, rb);
			DataManager::addFeature(wf.id, wf);
		}
		if(i<=rb_num){
			auto rb1 = Rabbit(Utils::getSerNum());
			DataManager::addFeature(rb1.id, rb1);
		}
		if (i <= carrot_num){
			auto ca = Carrot(Utils::getSerNum());
			DataManager::addFeature(ca.id, ca);
		}
	}

	auto it = DataManager::instance->featuremap.begin();
	for (it; it != DataManager::instance->featuremap.end(); it++){
		std::thread td1(std::bind(&Feature::mainloop, &it->second));
		td1.detach();
	}

	Utils::print("DataManager::init data over====================");
}

void DataManager::featureCallHelp(Feature *f){

}

void DataManager::featureCallTogether(Feature *f){

}

void DataManager::featureEat(Feature *f){

}