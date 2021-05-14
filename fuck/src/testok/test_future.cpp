#include <iostream>
#include <thread>
#include <future>

using namespace std;

int main(int argc, char **argv){
	promise<int > p;
	future<int> f = p.get_future();
	thread([&p](){p.set_value(-1);}).detach();
	f.wait();
	cout << "val:" << f.get() << endl;
	return 0;
}
