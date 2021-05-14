#include <iostream>
#include <thread>

int main(int argc, char **argv){
	unsigned int count =  std::thread::hardware_concurrency();
	std::cout << "thread count:" << count << std::endl;
	return 0;
}
