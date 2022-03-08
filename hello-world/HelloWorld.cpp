#include "HelloWorld.h"
#include <iostream>

void HelloWorld::hello() {
  std::cout << "Hello World!" << std::endl;
}

int main(){
	HelloWorld hlw;
	hlw.hello();
	return 0;
}

