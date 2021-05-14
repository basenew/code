#pragma once
#include <iostream>

using namespace std;

class CatStr{
public:
	CatStr(const string& s1, const string& s2);
    string get();
private:
	string _s1, _s2;
};

