#include <memory>
#include <iostream>
#include <functional>

using namespace std;

struct st_test{
int v;
char c;
string s;
};

void test(){
	//unique_ptr<st_test> up_test = make_unique<st_test>();
	unique_ptr<st_test> up_test(new st_test);
	up_test->v = 10000;
	up_test->c = 100;
	up_test->s = "string";
	cout << "v:" << up_test->v << " c:" << up_test->c << " s:" << up_test->s << endl;
}

int main1(int argc, char **argv){
	test();
}

#include <iostream>
#include <memory>
 
struct Foo {
    Foo() { std::cout << "Foo\n"; }
    ~Foo() { std::cout << "~Foo\n"; }
};
 
int main() 
{
    std::unique_ptr<Foo> p1;
 
    {
        std::cout << "Creating new Foo...\n";
        std::unique_ptr<Foo> p2( new Foo() );
        //p1 = p2; // 错误！不能复制 unique_ptr
        p1 = std::move(p2);
        std::cout << "About to leave inner block...\n";
 
        // Foo 实例将继续生存，尽管 p2 离开作用域
    }
 
    std::cout << "About to leave program...\n";
}

