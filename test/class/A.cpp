#include <iostream>

using namespace std;

class A
{
public:
	string name_;
	~A(){cout << "~A:" << name_ << endl;}
	A(const string name){cout << "construct A:" << name << endl;name_ = name;}
	A(const A& a){cout << "construct A by copy:" << a.name_ << endl;name_ = a.name_;}
	A& operator=(const A& a){cout << "operator =" << endl;};
};

void f(A a)
{
	cout << "f:" << a.name_ << endl;
	cout << "addr2:" << (long)&a << endl;
}

int main(int argc, char* argv[])
{
	A a1("a1");
	A a2(a1);
	A a3 = a1;
	A& a4 = *new A("a4");
	a4.~A();
	cout << "addr1:" << (long)&a3 << endl;
	f(a3);
	return 0;
}
