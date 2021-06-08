#include <iostream>
#include "res.h"

using namespace std;

bool check_argv(int argc, char** argv){
	return true;
}

void test(){
	char arr[8*1024*1024 - 126*1024];//stack default size 8M
	arr[0] = 100;
	arr[sizeof(arr) - 1] = 100;
}

int main(int argc, char** argv){
	if(!check_argv(argc, argv)) return 1;

	cout << "start test!" << endl;

	test();

	cout << "test finished!press any key to exit" << endl;
	getchar();

	return 0;
}
