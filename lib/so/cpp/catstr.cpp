#include "catstr.hpp"

CatStr::CatStr(const string& s1, const string& s2):_s1(s1), _s2(s2){
	cout << "cat " << _s1 << " and " << _s2 << endl;
}

string CatStr::get(){
    return _s1 + _s2;
}

