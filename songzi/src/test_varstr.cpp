#pragma once
#include <iostream>
#include <unistd.h>
#include "data.h"

using namespace std;

void test()
{
	VarStr s1;
	VarStr s2("s2");
	VarStr s3(s2);
	VarStr s4 = s2;

	string str("s5");
	VarStr s5(str);
	str = "s6";
	VarStr s6 = str;

	s6.~VarStr();
}

int main(int argc, char **argv)
{
	test();

	while (1) usleep(1000);
	return 0;
}
