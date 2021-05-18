#include<iostream>
using namespace std;
class Base
{
protected:
	int _base;
public:
	void fun()
	{
		cout << "Base::fun" << endl;
	}
};

//class A:virtual public Base
class A:public Base
{
protected:
	int _a;
};

class B :virtual public Base
//class B :public Base
{
protected:
	int _b;
};
class D :public A, public B
{
private:
	int _d;
};
int main()
{
	A a;
	cout << "sizeof a:" << sizeof(a) << endl;
	D d;
	cout << "sizeof D:" << sizeof(d) << endl;
	//d.fun();
	getchar();
}
