#include <iostream>

using namespace std;

class Person {
public:
    int* data;
    Person() : data(new int[1000000]) {cout<<"Person()"<<endl;}
    ~Person() { delete [] data; cout<<"~Person()"<<endl;}

    // 拷贝构造函数，需要拷贝动态资源
    Person(Person&& other) : data(new int[1000000]) {
        //std::copy(other.data,other.data+1000000,data);
		cout << "Person(const Person& other)" << endl;
    }
};

void func(Person&& p){
    // do_something
    cout << "p:" << &p << " data:" << p.data << endl;
} 

int main(){
    Person p;
    func(p); // 调用func时，会调用Person的拷贝构造函数来创建实参
    return 0;
}

