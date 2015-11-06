#ifndef _FEATUREH_
#define _FEATUREH_
#include <string>
#include <vector>

#include "CmdInfo.h"

class Feature
{
public:
	Feature();
	~Feature();

	int type;
	int id;
	int state;
	int x;
	int y;
	int speed;
	int angel;
	std::vector<cmdinfo> msgboxs;
	int current_time = 0;

	void sendMsgToObj(Feature f, cmdinfo msg);
	void reviceMsg(Feature f, cmdinfo msg);
	void checkMsgBox();
	void mainloop();

	void move();
	void run();
	void eat();
	void callHelp();
	void callTogether();

	
};
#endif

