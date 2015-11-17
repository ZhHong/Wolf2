#include <thread>
#include "DataManager.h"
#include "Utils.h"
#include <iostream>


DataManager* DataManager::instance = nullptr;
std::map<int, Feature *> DataManager::featuremap = std::map<int, Feature*>();
std::vector<std::vector<int>> DataManager::loainfo = std::vector<std::vector<int>>();
std::map<int, std::thread::id> DataManager::threadmap = std::map<int, std::thread::id>();
int checkAction(int f_type1, int f_type2, float distance);

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

std::map<int, Feature*>::iterator DataManager::getFeature(int id){
	return  DataManager::featuremap.find(id);
}

void DataManager::addFeature(int id, Feature *f){
	//Utils::print("insert id====="+std::to_string(id));
	DataManager::instance->featuremap.insert(std::pair<int, Feature*>(id, f));
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
			Wolf * wf =new  Wolf(Utils::getSerNum());
			//DataManager::addFeature(rb.id, rb);
			DataManager::addFeature(wf->id, wf);
		}
		if(i<=rb_num){
			auto rb1 = new Rabbit(Utils::getSerNum());
			DataManager::addFeature(rb1->id, rb1);
		}
		if (i <= carrot_num){
			auto ca = new Carrot(Utils::getSerNum());
			DataManager::addFeature(ca->id, ca);
		}
	}

	auto it = DataManager::instance->featuremap.begin();
	for (it; it != DataManager::instance->featuremap.end(); it++){
		std::thread td1(std::bind(&Feature::mainloop, &(*(it->second))));
		DataManager::threadmap.insert(std::pair<int, std::thread::id>(it->second->id, td1.get_id()));
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
	//Utils::print("datamanager map size====================");
	//Utils::print(DataManager::instance->featuremap.size());
	auto it = DataManager::instance->featuremap.begin();
	std::vector<int> temp;
	while (it != DataManager::instance->featuremap.end()){
		auto f = it->second;
		//if (f.type == type)
		temp.clear();
		temp.push_back(f->id);
		temp.push_back(f->type);
		temp.push_back(f->x);
		temp.push_back(f->y);
		temp.push_back(f->x + Utils::sqr_l);
		temp.push_back(f->y + Utils::sqr_l);
		temp.push_back(f->state); //state 1 run/alive 0 die 2 hunte 3 runaway 4 call helip 5 call danger
		DataManager::loainfo.push_back(temp);
		it++;
	}
	return loainfo;
}

std::thread::id DataManager::getFeatureThreadId(int fid){

	auto ftd=DataManager::threadmap.find(fid);
	if (ftd != DataManager::threadmap.end()){
		return ftd->second;
	}
	return std::thread::id();
}

void DataManager::checkDistance(Feature *f){
	int x = f->x;
	int y = f->y;
	auto it = DataManager::featuremap.begin();
	while (it!=DataManager::featuremap.end())
	{
		if (it->second->id !=f->id && f->type!=1){
			//remove self
			//get 2 obj type,id,pointer
			//dis=sqrt(pow(x1-x2,2)+pow(y1-y2,2))
			float dis = 0; sqrt(pow(f->x - it->second->x, 2) + pow(f->y - it->second->y, 2));
			int state = checkAction(f->type, it->second->type, dis);
			if (state !=1){
				//not normal state
			}
			else{
				//set normal state
			}
		}
	}
}

//check action to all
int checkAction(int f_type1,int f_type2,float distance){
	int state = 0;
	switch (f_type1)
	{
	//rabbit
	case 2:
		break;
	//wolf
	case 3:
		break;
	default:
		break;
	}
	return state;
}