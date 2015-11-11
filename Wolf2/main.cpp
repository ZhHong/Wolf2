#include "DataManager.h"
#include "OpenglManager.h"


int main(int argc,char * argv[]){
	auto dataManager = DataManager::getInstance();
	//init feature data
	dataManager->initFeatrue();
	auto openglManager = OpenglManager::getInstance();
	//init opengl window
	openglManager->initOpenglState(argc,argv);
	return 0;
}