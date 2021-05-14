#include <iostream>

int main(int argc, char **argv){
	int arr[5]{1,2,3,4,5};
	for(auto i:arr){
		std::cout << i << " " << std::endl;
	}	
	return 0;
}
