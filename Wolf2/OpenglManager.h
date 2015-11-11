#ifndef _OPENGLMANAGERH_
#define _OPENGLMANAGERH_
#include <vector>
#include <GL\glut.h>

class OpenglManager
{
public:
	~OpenglManager();
	static OpenglManager * getInstance();
	int initOpenglState(int argc, char * agrv[]);
private:
	OpenglManager();
	static OpenglManager * instance;
	
};
#endif

