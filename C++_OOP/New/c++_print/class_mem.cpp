//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class TestMem {
public:
    static TestMem *create() {
        return new TestMem();
    }
    virtual ~TestMem() {
        cout << "(TestMem)" << endl;
    }
private:
    TestMem() { cout << "(TestMem)" << endl; }
};

class C {
public:
    int c1;
};

class B1 :virtual public C {
public:
    int b1;
protected:
};

class B2 : virtual public C {
public:
    int b2;
protected:
};

class A3 : public B1, public B2 {
public:
    int a1;

};

int main() {
//    TestMem tm1;
//    auto tm2 = new TestMem;

    // instance
    TestMem *tm3 = TestMem::create();

    //虚继承
    {
        A3 a;
        a.C::c1 = 1;
    }
    return 0;
}