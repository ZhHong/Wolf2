#ifndef _DATAMANAGERH_
#define _DATAMANAGERH_

#include<map>
#include "Feature.h"
#include "Animal.h"
#include "Wolf.h"
#include "Rabbit.h"


class DataManager
{
public:
	int proc;
	std::map<int ,Feature>::iterator getFeature(int id);
	void addFeature(int id ,Feature f);
	void removeFeature(int id);

	static DataManager * getInstance();
	void initFeatrue();


private:
	DataManager();
	~DataManager();
	static DataManager * instance;

	std::map<int, Feature> featuremap;


};
#endif
