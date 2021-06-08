#include <iostream>
#include <arpa/inet.h>
#include <cstdio>

using namespace std;

int main(){

    short s=1;
    if(s == htons(s))cout<<"大端"<<endl;
    else cout<<"小端"<<endl;

    return 0;
}
