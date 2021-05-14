#include <iostream>
#include <thread>

using namespace std;

int main(int argc, char **argv){
	thread t;
	cout << "thread id:" << t.get_id() << endl;
	return 0;
}


