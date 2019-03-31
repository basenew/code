#include <iostream>
#include <string.h>

using namespace std;
#define KB     1024
#define MB     1024*KB
#define GB     1024*MB

int main(int argc, char** argv)
{
	long size = MB;
	while (1)
	{
		cout << size << endl;
		char* mem = new char[size];
		strcpy(mem, "hello");
		size = size*2;
	}	
	char stack_mem[size]; 
	//cout << "stack memory size:" << size << endl;

	size = GB;
	char *heap_mem = new char[size]; 
	cout << "heap memory size:" << size << endl;
}
