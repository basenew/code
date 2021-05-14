#include <iostream>
#include <memory>
#include <stdlib.h>

std::string *pname;
	
struct Foo
{
    Foo():name("basenew") { std::cout << "Foo::Foo\n"; pname = &name; }
    ~Foo() { std::cout << "Foo::~Foo\n"; }
    void bar() { std::cout << "Foo::bar name:" << *pname << std::endl; }
	std::string name;
};

void f(const Foo &)
{
    std::cout << "f(const Foo&)\n";
}

struct D
{
    void operator()(Foo* foo)
    {
        std::cout << "D operator()" << std::endl;
        delete foo;
    }
};

int main()
{
    std::cout << "TestOwner...................." << std::endl;
    //1. new object.
    std::unique_ptr<Foo> p1(new Foo);  // p1 owns Foo
    if (p1) p1->bar();

    {
        std::unique_ptr<Foo> p2(std::move(p1));  // now p2 owns Foo
  std::cout << "address of p1: " << p1.get() << " address of p2: " << p2.get() << std::endl;
        f(*p2);

        p1 = std::move(p2);  // ownership returns to p1
        std::cout << "address of p1: " << p1.get() << " address of p2: " << p2.get() << std::endl;
        p2->bar();
        std::cout << "destroying p2...\n";
    }

    p1->bar();
 return 0;
}
