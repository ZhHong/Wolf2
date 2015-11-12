#ifndef _UTILSH_
#define _UTILSH_
#include <string>

class Utils
{
public:
	Utils();
	~Utils();
	void static print(int num);
	void static print(std::string str);
	int static getSerNum();
	static int bgval;
	static float sqr_l;
	static float wind_w;
	static float wind_h;
	static double random(int b,int e);
	static double random();
};
#endif

