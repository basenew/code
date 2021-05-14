//#include "catstr.hpp"
#include <iostream>
#include <dlfcn.h>
#include <errno.h>

using namespace std;

void test_load_so(const string& name){
	void* hdl = dlopen(name.c_str(), RTLD_LAZY);
	if (hdl == nullptr){
		cout << "load " << name << " err:" << errno << endl;
        return;
    }

	cout << "hdl:" << hdl << endl;
	typedef void (*catstr)(const char* s1, const char* s2, char*& cs);
	catstr func = (catstr) dlsym(hdl, "catstr_api");
	if (func == nullptr){
		cout << "catstr not found " << " err:" << errno << endl;
        return;
    }
	char* str;
	func("123", "456", str);
	if (str){
		cout << "cat string is " << str << endl;
		delete[] str;
	}else{
		cout << "str is null" << endl;
	}
	dlclose(hdl);
}

int main(int argc, char** argv){
	//CatStr catstr("123", "456");
    //string res = catstr.get();
    //cout << res << endl;
	test_load_so("libcatstr.so");
	return 0;
}
