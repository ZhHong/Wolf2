#include <iostream>
#include <thread>
#include <map>

#include "Wolf.h"
#include "Rabbit.h"
#include "Utils.h"

int main(){
	std::map<int, std::thread> wolfmap;
	for (int i = 1000; i < 1004; i++){
		//http://blog.csdn.net/zhq651/article/details/8491277
		//at the end only 3 1003 run
		std::thread td1(std::bind(&Wolf::mainloop, &Wolf(i)));
		td1.detach(); //join wait for complete detach not wait
		//wolfmap.insert(std::pair<int, std::thread>(i, td1));
		Utils::print(std::to_string(i)+" times");
	}

	system("pause");
}