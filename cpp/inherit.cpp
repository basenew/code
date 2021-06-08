#include <iostream>
#include "res.h"

using namespace std;

bool check_argv(int argc, char** argv){
	return true;
}

void test(){
	class Res1:public Res{};
	cout << "sizeof std::string:" << sizeof(string) << endl;
	cout << "sizeof Res:" << sizeof(Res) << endl;
	cout << "sizeof Res1:" << sizeof(Res1) << endl;
}

int main(int argc, char** argv){
	if(!check_argv(argc, argv)) return 1;

	cout << "start test!" << endl;

	test();

	cout << "test finished!" << endl;
	getchar();

	return 0;
}
