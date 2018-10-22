#include <iostream>

using namespace std;

class A
{
int a;
public:
	A(int aa):a(aa){cout << "construct a:" << aa << endl;};
	~A(){cout << "deconstruct a:" << endl;};
};

A& f()
{
	A *a = new A(10);
	cout << "f::a:" << a << endl;
	return *a;
}


int main(int argc, char* argv[])
{
	A& a = f();
	cout << "a:" << &a << endl;
	delete &a;
	
	return 0;
}
