#include "catstr_api.hpp"
#include "catstr.hpp"
#include <string.h> 

void catstr_api(const char* s1, const char* s2, char*& cs){
	CatStr catstr(s1, s2);
    string str = catstr.get();
	cs = new char[str.size()];
	strcpy(cs, str.c_str());
}
