#include <iostream>
#include <typeinfo>

using namespace std;
class basenew{};
int main(){
	basenew a;
	cout << typeid(a).name() << endl;
}

