#include<iostream>
using namespace std;

/*
template<class T>
class Base {
public:
    T m;
};

class Son1 : public Base<int> {
};

template<class T1, class T2>
class Son2 : public Base<T1> {
public:
    Son2() {
        cout << "T1的数据类型为：" << typeid(T1).name() << endl;
        cout << "T2的数据类型为：" << typeid(T2).name() << endl;
    }
    T2 obj;
};

void test() {
    Son1 s1;
    Son2<int, char> s2;
}
int main() {
    test();
    system("pause");
    return 0;
}*/


class XYZ {
public:
    int x, y, z;
    XYZ(int a, int b, int c) : x(a), y(b), z(c) {}
    void print() {
        cout << "x" << x << "y" << y << "z" << z << endl;
    }
protected:
};

//模板类 继承  普通类
template<class T>
class GoodXYZ : public XYZ {
public:
    T t;
    GoodXYZ( int a, int b, int c,T t1) : XYZ(a, b, c), t(t1) {}

    void print() {

        cout << "x" << x << "y" << y << "z" << z << endl;
    }
protected:
};

class RunClass : public GoodXYZ<int> {
public:
        int dd =1000;
    RunClass(int a, int b, int c, int t1, int dd) : GoodXYZ<int>(a, b, c, t1), dd(dd) {}
    void print() {
        cout << dd<<x<<y<<z<<t << endl;

        cout << "x" << x << "y" << y << "z" << z << endl;
    }
protected:
};

int main() {
    RunClass run1(1, 2, 3, 4, 5);
    run1.print();
    return 0;
}