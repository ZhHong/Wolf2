#include "OpenglManager.h"
#include "Utils.h"
#include "DataManager.h"

void RenderScene(void);
void SetupRC(void);
void ChangeSize(GLsizei w, GLsizei h);
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
	glutCreateWindow("Wolf2");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ChangeSize);
	SetupRC();
	glutMainLoop();
	return 1;
}

//called to draw scene
void RenderScene(void){
	//clear the window with current clearing color
	glClear(GL_COLOR_BUFFER_BIT);
	//set current drawing color to red
	glColor3f(1.0f, 0.0f, 0.0f);
	//getData(); get feature data 
	getData(1);
	auto it = tempvec.begin();
	while (it != tempvec.end())
	{
		//draw a filled rectangle with current color
		//glRectf(-Utils::sqr_l, Utils::sqr_l, Utils::sqr_l, -Utils::sqr_l);
		glRectf(-1.0f,1.0f,1.0f,-1.0f);
	}
	//flush drawing commands
	glFlush();
}

//set up the rendering state
void SetupRC(void){
	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
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
	aspectRadio = (GLfloat)w / (GLfloat)h;

	if (w <= h)
		glOrtho(-100.0, 100.0, -100.0 / aspectRadio, 100.0 / aspectRadio, 1.0, -1.0);
	else
		glOrtho(-100.0*aspectRadio, 100.0*aspectRadio, -100.0, 100.0, 1.0, -1.0);
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