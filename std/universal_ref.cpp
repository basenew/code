#include <iostream>

using namespace std;

class Mystring{
public:
Mystring(const char* str):data((char*)str){
cout << "Mystring" << endl;
};
~Mystring(){
cout << "~Mystring" << endl;
};

ostream& operator<<(ostream& o){
	return o << data;
};

private:
	char* data;
};

Mystring f() 
{ 
return "abc"; 
}
void g() {
    //const string &s = f();       // still legal?
    Mystring s = f();       // still legal?
//	cout << "addr abc:" << &("abc") << " addr s:" << &s << endl;
    //string &s = f();       // still legal?
    cout << "g() finish" << endl;
}

int main(){
	g();
	return 0;
}

