#include <stdio.h>

int printf(const char* format, ...);
int g_init_v = 84;
int g_uninit_v;
const int c_i = 100;

void func1(int i){
	printf("%d\n", i);
}

int main(){
	static int s_v = 85;
	static int s_v2;

	int a = 1;
	int b;
	func1(s_v + s_v2 + a + b);
	return a;
}



