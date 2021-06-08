#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <typeinfo>

using namespace std;

bool check_argv(int argc, char** argv){
	return true;
}

class empty{};
class empty_with_member_func{public:void func(){};};
class empty_with_virtual_member_func{public:virtual void virtual_member_func(){};};
class with_int{int i;};
class with_int_char:public with_int{char i;};

struct llong_char_int{
	long long ll;
	char c;
	int i;
};

struct llong_char_char_int{
	long long ll;
	char c;
	char c2;
	int i;
};

#pragma pack(push)
#pragma pack(1)
struct llong_char_int_char_pack1{
	long long ll;
	char c;
	int i;
	char c2;
};
#pragma pack(pop)

#pragma pack(push)
#pragma pack(2)
struct ex_llong_char_int_char_pack2:public llong_char_int_char_pack1{};
#pragma pack(pop)


struct llong_char_int_char{
	long long ll;
	char c;
	int i;
	char c2;
};

template<class T>
void print_type_size(){
	cout << "size of " << typeid(T).name() << " :" << sizeof(T) << endl;
}

void test_class_with_member(){
	print_type_size<with_int>();
	print_type_size<with_int_char>();
	print_type_size<llong_char_int>();
	print_type_size<llong_char_int_char>();
	print_type_size<llong_char_char_int>();
	print_type_size<llong_char_int_char_pack1>();
	print_type_size<ex_llong_char_int_char_pack2>();

}

void test_inner_type(){
	cout << "size of void*:" << sizeof(void*) << endl;
	cout << "size of char:" << sizeof(char) << endl;
	cout << "size of short:" << sizeof(short) << endl;
	cout << "size of int:" << sizeof(int) << endl;
	cout << "size of long:" << sizeof(long) << endl;
	cout << "size of float:" << sizeof(float) << endl;
	cout << "size of double:" << sizeof(double) << endl;
	cout << "size of long long:" << sizeof(long long) << endl;

	cout << "size of string:" << sizeof(string) << endl;
	cout << "size of vector:" << sizeof(vector<int>) << endl;
	cout << "size of map:" << sizeof(map<int,int>) << endl;
	cout << "size of list:" << sizeof(list<int>) << endl;
	cout << "size of empty class:" << sizeof(empty) << endl;
	cout << "size of empty class with member function:" << sizeof(empty_with_member_func) << endl;
	cout << "size of empty class with virtual member function:" << sizeof(empty_with_virtual_member_func) << endl;
}

int main(int argc, char** argv){
	if(!check_argv(argc, argv)) return 1;

	cout << "start test!" << endl;

	test_class_with_member();

	cout << "test finished!" << endl;
	getchar();

	return 0;
}
