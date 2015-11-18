#ifndef _DATAMANAGERH_
#define _DATAMANAGERH_

#include<map>
#include<vector>
#include <thread>
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
	std::thread::id getFeatureThreadId(int id);
	std::vector<std::vector<int>>getFeatureDataVecByType(int type);

	void checkDistance(Feature * f);
	bool getLock();
	void refreelock();
private:
	DataManager();
	~DataManager();
	static DataManager * instance;

	static std::map<int, Feature*> featuremap;

	static std::vector<std::vector<int>> loainfo;

	static std::map<int, std::thread::id> threadmap;

	static int datainit;

	static int datalock;
};
#endif
