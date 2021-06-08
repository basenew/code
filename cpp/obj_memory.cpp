#include <iostream>
//#include "res.h"
#include "utils.h"

using namespace std;

bool check_argv(int argc, char** argv){
	return true;
}

class Res{public:int i;Res():i(255){};};
class ResEx:public Res{public:virtual void vfunc(){};};

void test(){
	print_type_size<Res>();
	print_type_size<ResEx>();
	Res r1;
	ResEx r2;
	ResEx r3;
	cout << endl;
}

int main(int argc, char** argv){
	if(!check_argv(argc, argv)) return 1;

	cout << "start test!" << endl;

	test();

	cout << "test finished!press any key to exit" << endl;
	getchar();

	return 0;
}

/*
start test!
size of 3Res :4
size of 5ResEx :16

Breakpoint 1, test () at obj_memory.cpp:20
20              cout << endl;
(gdb) p r1
$1 = {i = 255}
(gdb) p r2
$2 = {<Res> = {i = 255}, _vptr.ResEx = 0x555555755d38 <vtable for ResEx+16>}
(gdb) p r3
$3 = {<Res> = {i = 255}, _vptr.ResEx = 0x555555755d38 <vtable for ResEx+16>}
(gdb) x/16x &r1
0x7fffffffe2dc: 0x000000ff      0x55755d38      0x00005555      0x000000ff
0x7fffffffe2ec: 0x00007fff      0x55755d38      0x00005555      0x000000ff
0x7fffffffe2fc: 0x00000000      0xffffe330      0x00007fff      0x512f6900
0x7fffffffe30c: 0x17be8f18      0xffffe330      0x00007fff      0x55554be9
(gdb) x/16x &r3
0x7fffffffe2f0: 0x55755d38      0x00005555      0x000000ff      0x00000000
0x7fffffffe300: 0xffffe330      0x00007fff      0x512f6900      0x17be8f18
0x7fffffffe310: 0xffffe330      0x00007fff      0x55554be9      0x00005555
0x7fffffffe320: 0xffffe418      0x00007fff      0x00000000      0x00000001
(gdb) x/16x &r2
0x7fffffffe2e0: 0x55755d38      0x00005555      0x000000ff      0x00007fff
0x7fffffffe2f0: 0x55755d38      0x00005555      0x000000ff      0x00000000
0x7fffffffe300: 0xffffe330      0x00007fff      0x512f6900      0x17be8f18
0x7fffffffe310: 0xffffe330      0x00007fff      0x55554be9      0x00005555
*/

