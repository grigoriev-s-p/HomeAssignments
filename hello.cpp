#include "hello.h"
#include <iostream>
void myproject::sayHello() {
	std::cout << "Hello, world!" << std::endl;
	while(true){
		string s;
		cin>>s;
		cout<<"Hello, "<<s<<"!"<<endl;
	}
}
