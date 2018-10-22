#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int a, b = 0;
	//int c = a/b;
	string str("test string");
	const char* p = str.c_str();
	cout << p << endl;
	delete[] p;
	for (int i = 0; i < 100; i++)
	cout << p << endl;
	return 0;
}
