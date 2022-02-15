//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class T>
class Iterator_1 {
public:
    typedef T value_type;
    typedef value_type *pointer;
    typedef value_type &reference;
};

template<class T>
class Iterator_2 {
public:
    typedef T value_type;
    typedef value_type *pointer;
    typedef value_type &reference;
};

template<class T>
struct Traits {
};
template<class T>
struct Traits<T *> {
    typedef T value_type;
    typedef value_type *pointer;
    typedef value_type &reference;
};

class A {
public:
    void show() {}
};

class B;

int main() {
    Iterator_1<int>::value_type t1 = 100;
    cout << t1 << endl;
    Iterator_2<double>::value_type t2 = 6.19;
    cout << t2 << endl;
    Traits<double *>::value_type t3 = 3.33;
    Iterator_1<A>::pointer iter;
    iter->show();
    cout << t3 << endl;
}