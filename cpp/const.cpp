#include <iostream>
#include "res.h"

using namespace std;

bool check_argv(int argc, char** argv){
	return true;
}

string foo(){
	const char* s = "foo";
	cout<<"ps:"<<static_cast<const void*>(s)<<endl;
	return s;
};

void bar(string s){
	cout<<"ps2:"<<reinterpret_cast<const void*>(s.data())<<endl;
	cout<<s<<endl;
};

class A{
public:
	class Ins{
	private:
		static const int inner_type = 5;//ok allow inner class
		static const Res inner_res;//ok
		//static const Res inner_res("inner res");//not allow
	};
};

//Res A::Ins::inner_res("inner res");
void test_staic_const_member(){
#if 1 
	class LocalIns{
	private:
		static int inner_type = 5;//not allow in local class
		//static const int inner_type = 5;//not allow in local class
	};
	A::LocalIns local_ins;
#endif
	A::Ins ins;
}

void test(){
	//bar(foo());
	//bar("hello world");
	test_staic_const_member();
}


int main(int argc, char** argv){
	if(!check_argv(argc, argv)) return 1;

	cout << "start test!" << endl;

	test();

	cout << "test finished!press any key to exit" << endl;
	getchar();

	return 0;
}
