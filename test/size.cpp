#include <iostream>

using namespace std;
struct S{
	short a;
	char b;
	int *c;
	unsigned long d;
};
int main(int argc, char* argv[])
{
	cout << "bool:" << sizeof(bool) << endl;
	cout << "char:" << sizeof(char) << endl;
	cout << "char*:" << sizeof(char*) << endl;
	cout << "int:" << sizeof(int) << endl;
	cout << "long:" << sizeof(long) << endl;
	cout << "long long:" << sizeof(long long) << endl;
	cout << "float:" << sizeof(float) << endl;
	cout << "double:" << sizeof(double) << endl;
	cout << "struct S:" << sizeof(struct S) << endl;
}
