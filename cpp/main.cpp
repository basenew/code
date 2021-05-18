#include "smart_ptr.h"
#include "res.h"

void test_smart_ptr(){
	smart_ptr<Res> pr(new Res);
	//smart_ptr<Res> pr2(pr);
	//smart_ptr<Res> pr3;// = pi;
	//pr3 = pr;
}

int main(){
	//test_smart_ptr();
	int&& a = 100;
	int i = 10;
	int&& c = std::move(i);
}

