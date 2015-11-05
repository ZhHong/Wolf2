#ifndef _CMDINFOH_
#define _CMDINFOH_
#include <string>

struct cmdinfo
{
	int type = 0;
	int modelId = 0;
	int actionId = 0;
	std::string data = "";
};

#endif