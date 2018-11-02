#include <iostream>
#include <stdio.h>
#include <sys/socket.h>
#include <sys/types.h>

using namespace std;

int main(int argc, char** argv)
{
	long num = 0;	
	char name[256];
	int len;
	while (++num)
	{
		cout << num << endl;
		//int fd = socket(AF_INET, SOCK_STREAM, 0);
		sprintf(name, "%ld.t", num);
		FILE* f = fopen(name, "w");
		if (f)
		{
			len = fwrite("12312", 1, 5, f);
			fflush(f);
		}
	}	
	return 0;
}
