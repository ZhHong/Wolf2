#include <iostream>
#include <thread>
#include <map>
#include "DataManager.h"
#include "Feature.h"
#include "Wolf.h"
#include "Rabbit.h"
#include "Utils.h"

int main(){
	auto dataManager = DataManager::getInstance();


	dataManager->initFeatrue();
	//std::map<int, Feature> featuremap;
	//std::map<int, Wolf> wolfmap;
	//std::map<int, Rabbit>rabbitmap;
	//for (int i = 1000; i < 1004; i++){
	//	//http://blog.csdn.net/zhq651/article/details/8491277
	//	//at the end only 3 1003 run
	//	//std::thread td1(std::bind(&Wolf::mainloop, &Wolf(i)));
	//	//td1.detach(); //join wait for complete detach not wait
	//	////wolfmap.insert(std::pair<int, std::thread>(i, td1));
	//	//Utils::print(std::to_string(i)+" times");
	//	auto wf = Wolf(Utils::getSerNum());
	//	auto rb = Rabbit(Utils::getSerNum());
	//	//wolfmap.insert(std::pair<int, Wolf>(wf.id, wf));
	//	//rabbitmap.insert(std::pair<int, Rabbit>(rb.id, rb));
	//	featuremap.insert(std::pair<int, Feature>(wf.id, wf));
	//	featuremap.insert(std::pair<int, Feature>(rb.id, rb));
	//	dataManager->addFeature(wf.id, wf);
	//	dataManager->addFeature(rb.id, rb);
	//}
	////std::map<int, Wolf>::iterator it;
	////for (it = wolfmap.begin(); it != wolfmap.end(); ++it){
	////	std::thread td1(std::bind(&Wolf::mainloop, &it->second));
	////	td1.detach();
	////}
	//auto it = featuremap.begin();
	//for (it; it != featuremap.end(); it++){
	//	std::thread td1(std::bind(&Feature::mainloop, &it->second));
	//	td1.detach();
	//}

	system("pause");
}