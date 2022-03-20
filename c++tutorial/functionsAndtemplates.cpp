#include <iostream>
#include <memory>
using namespace std;

template<class T>
void Swap(T& a,T& b){
    T temp = a;
    a =b;
    b =temp;
}
int main() {
    int a = 5, b=7;
    Swap(a,b);
    cout<<a<<" - "<<b<<endl;

    char c ='c',d ='d';
    Swap(c,d);
    cout<<c<<" - "<<d<<endl;

    return 0;
}
