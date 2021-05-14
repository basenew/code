#include <memory>
#include <iostream>
#include <stdio.h>

using std::shared_ptr;
using std::cout;
using std::endl;
using std::string;

class A{
public:
	A(const string& name):name_(name){cout << "A() " << name_ << endl;}
	~A(){cout << "~A()" << name_ << endl;}
private:
	string name_;
};

void test_acc_shared_ptr(shared_ptr<A>& pa){
	pa.reset(new A("1"));
	cout << "use count:" << pa.use_count() << endl;
}


int main(int argc, char** argv){
	shared_ptr<A> pa(nullptr);//(new A);
	test_acc_shared_ptr(pa);
	cout << "test_acc_shared_ptr a1" << endl;
	getchar();
	shared_ptr<A> pa1(new A("2"));//(new A);
	cout << "new a2" << endl;
	getchar();
	pa = pa1;
	cout << "pa = pa1" << endl;
	getchar();
//	A a = A();
	return 0;
}



