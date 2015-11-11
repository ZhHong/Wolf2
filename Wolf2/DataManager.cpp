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
	delete DataManager::instance;
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

std::vector<std::vector<int>> DataManager::getFeatureDataVecByType(int type){
	//clear temp data
	DataManager::loainfo.clear();
	//[[id,type,x1,y1,x2,y2,speed,angel]]--[-1,1,1,-1] cross line (x1,y1),(x2,y2)
	auto it = DataManager::instance->featuremap.begin();
	std::vector<int> temp;
	while (it != DataManager::instance->featuremap.end()){
		auto f = it->second;
		//if (f.type == type)
		temp.clear();
		temp.push_back(f.id);
		temp.push_back(f.type);
		temp.push_back(f.x-Utils::sqr_l/2);
		temp.push_back(f.y + Utils::sqr_l / 2);
		temp.push_back(f.x + Utils::sqr_l / 2);
		temp.push_back(f.y - Utils::sqr_l / 1);
		DataManager::loainfo.push_back(temp);
		++it;
	}
	return loainfo;
}