#include <iostream>
#include "res.h"

using namespace std;

bool check_argv(int argc, char** argv){
	return true;
}

void test(){

}

int main(int argc, char** argv){
	if(!check_argv(argc, argv)) return 1;

	cout << "start test!" << endl;

	test();

	cout << "test finished!press any key to exit" << endl;
	getchar();

	return 0;
}
