#include <iostream>
#include "res.h"

using namespace std;

bool check_argv(int argc, char** argv){
	return true;
}

bool is_little_end(){
	short v = 0x0001;
	return *((char*)&v) > 0;
}

void test(){
	cout << "is little end:" << is_little_end() << endl;
}

int main(int argc, char** argv){
	if(!check_argv(argc, argv)) return 1;

	cout << "start test!" << endl;

	test();

	cout << "test finished!press any key to exit" << endl;
	getchar();

	return 0;
}
