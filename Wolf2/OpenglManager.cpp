#include <math.h>
#include "OpenglManager.h"
#include "Utils.h"
#include "DataManager.h"

void RenderScene(void);
void SetupRC(void);
void ChangeSize(GLsizei w, GLsizei h);
void TimerFunction(int value);
std::vector<std::vector<int>>getData(int type);
OpenglManager * OpenglManager::instance = nullptr;
std::vector<std::vector<int>> tempvec;

OpenglManager::OpenglManager()
{
}


OpenglManager::~OpenglManager()
{
	delete OpenglManager::instance;
}

OpenglManager * OpenglManager::getInstance(){

	if (OpenglManager::instance = nullptr)
		OpenglManager::instance = new OpenglManager();
	return OpenglManager::instance;
}
int OpenglManager::initOpenglState(int argc, char * argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(Utils::wind_w,Utils::wind_h);
	glutCreateWindow("Wolf2");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	glutTimerFunc(1,TimerFunction,1);
	SetupRC();
	glutMainLoop();
	return 1;
}

//called to draw scene
void RenderScene(void){
	//clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);
	//set current drawing color to red
	//glColor3f(1.0f, 0.0f, 0.0f);
	//getData(); get feature data 
	tempvec=getData(1);
	//[[id,type,x1,y1,x2,y2,speed,angel,/add op thread id]]
	auto datamanager = DataManager::getInstance();
	auto it = tempvec.begin();
	while (it != tempvec.end())
	{
		//draw a filled rectangle with current color
		//glRectf(-Utils::sqr_l, Utils::sqr_l, Utils::sqr_l, -Utils::sqr_l);
		//glRectf(-1.0f,1.0f,1.0f,-1.0f);
		auto cc = *it;
		//Utils::print("============================");
		//Utils::print(cc[1]);
		//Utils::print(cc[2]);
		//Utils::print(cc[3]);
		//Utils::print(cc[4]);
		//Utils::print(cc[5]);
		if (cc[1] == 1){
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		if (cc[1] == 2){
			glColor3f(0.0f, 0.0f, 1.0f);
		}
		if (cc[1] == 3){
			glColor3f(1.0f, 0.0f, 0.0f);
		}
		glRectf(cc[2],cc[3],cc[2],cc[5]);
		//opengl draw numbers===== need number like-> id(x1,y1)
		float globel_x = (cc[2] + cc[4]) / 2;
		float globel_y = (cc[3] + cc[5]) / 2;
		//std::thread::id tid=datamanager->getFeatureThreadId(cc[0]);
		//std::string threadstr="0x " + std::to_string(tid.hash());
		//std::string needdraw = threadstr+"-"+std::to_string(cc[0]) + "-(" +std::to_string(int(globel_x))+","+std::to_string(int(globel_y))+ ")";
		std::string needdraw = "(" + std::to_string(int(globel_x)) + "," + std::to_string(int(globel_y)) + ")";
		int len = needdraw.length();
		glRasterPos3f(globel_x-len/2, globel_y + Utils::sqr_l , 0);
		for (int i = 0; i != len; i++){
			//GLUT_BITMAP_TIMES_ROMAN_10  need 10*10 space
			glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, needdraw[i]);
		}

		it++;
	}
	//flush drawing commands
	glFlush();
}

//set up the rendering state
void SetupRC(void){
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
}

//called by glut when window has changed size
void ChangeSize(GLsizei w, GLsizei h){
	
	GLfloat aspectRadio;
	if (h == 0)
		h == 1;
	//set viewport to window dimensiions
	glViewport(0, 0, w, h);

	//reset coordinate system
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	//establish clipping volume(left,right,bottom,top,near,far)
	//opengl center (0,0,0) is the center of the screen
	aspectRadio = (GLfloat)w / (GLfloat)h*3/4; //4/3

	//this set where you look at (xmin,xmax,ymin,ymax)
	//todo  add new x/y for my own
	if (w <= h)
		//glOrtho(-400.0, 400.0, -400.0 / aspectRadio, 400.0 / aspectRadio, 1.0, -1.0);
		glOrtho(0, w, 0, h / aspectRadio, 1.0, -1.0);
	else
		glOrtho(0, w*aspectRadio, 0, h, 1.0, -1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

std::vector<std::vector<int>>getData(int type){
	//clear data of temp vec
	tempvec.clear();
	auto dataManager = DataManager::getInstance();
	//[[id,type,x1,y1,x2,y2,speed,angel]]
	tempvec=dataManager->getFeatureDataVecByType(type);

	return tempvec;
}

void TimerFunction(int value){
	glutPostRedisplay();
	glutTimerFunc(1, TimerFunction, 1);
}