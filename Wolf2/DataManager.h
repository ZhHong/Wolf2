#ifndef _DATAMANAGERH_
#define _DATAMANAGERH_

#include<map>
#include<vector>
#include "Feature.h"
#include "Animal.h"
#include "Wolf.h"
#include "Rabbit.h"
#include "Carrot.h"


class DataManager
{
public:
	int proc;
	std::map<int ,Feature*>::iterator getFeature(int id);
	void addFeature(int id ,Feature * f);
	void removeFeature(int id);

	static DataManager * getInstance();
	void initFeatrue();

	void featureCallHelp(Feature *);
	void featureCallTogether(Feature *);
	void featureEat(Feature *);
	std::vector<std::vector<int>>getFeatureDataVecByType(int type);
private:
	DataManager();
	~DataManager();
	static DataManager * instance;

	static std::map<int, Feature*> featuremap;

	static std::vector<std::vector<int>> loainfo;

};
#endif
