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

};
#endif

