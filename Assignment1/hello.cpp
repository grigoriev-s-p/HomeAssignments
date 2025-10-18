/*
 * Sergey Grigoriev
 * st142081@student.spbu.ru
 * My project number one
*/
#include "hello.h"
#include <iostream>
void myproject::sayHello() {
	std::cout << "Hello, world!" << std::endl;
	while(true){
		std::string s;
		std::getline(std::cin,s);
		std::cout<<"Hello, "<<s<<"!"<<std::endl;
	}
}
