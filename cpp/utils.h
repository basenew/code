#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;

#define LDBG  cout
#ifdef FUNC
    #define INFUNC()  do{cout << "entry " << __FILE__ << ":" <<__LINE__<<":"<< __FUNCTION__ << endl;}while(0)
    #define OUTFUNC() do{cout << "exit "  << __FILE__ << ":" <<__LINE__<<":"<< __FUNCTION__ << endl;}while(0)
#else
    #define INFUNC()
    #define OUTFUNC()
#endif

template<class T>
void print_type_size(){
	cout << "size of " << typeid(T).name() << " :" << sizeof(T) << endl;
}

