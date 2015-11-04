#include <iostream>
#include "Wolf.h"

int main(){

	Wolf *wf = new Wolf();
	wf->move();

	std::cout << wf->x << "," << wf->y << std::endl;

	system("pause");
}