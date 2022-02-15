//
// 匿名仿函数

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;

template<class T>
class My_ptr {
    T *_ptr;
public:
    My_ptr(T *ptr) : _ptr(ptr) { cout << "(My_ptr)" << endl; }
    virtual ~My_ptr() {
        cout << "~(My_ptr)" << endl;
        delete (_ptr);
    }
    T &operator*() {
        return *_ptr;
    }
    T &operator->() {
        return _ptr;
    }
protected:
};

int main() {
    int a = 10;
    int *pInt = new int(20);
    {
        My_ptr<int> p(pInt);
//        My_ptr<int > p (&a);
        cout << *p << endl;
    }
    //Lambda
    [](int x) { cout << x * 2 << endl; }(10);
    auto f = [](int x) { cout << x * 2 << endl; };
    f(20);
    cout << "--------------------------" << endl;
    return 0;
}