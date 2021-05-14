#pragma once
#include <iostream>
#include <stdio.h>

using namespace std;

#define LDBG  cout
#define INFUNC() do{cout << "entry " << __FUNCTION__ << endl;}while(0)
#define OUTFUNC() do{cout << "exit " << __FUNCTION__ << endl;}while(0)
