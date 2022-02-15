//
//

#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;
//传指针
void PtrFunction(const char *data, size_t size) {
    cout << "sizeof(data) = " << sizeof(data) << endl;
}
//传数组  (转指针)
void PtrFunction(const char data[]) {
    cout << "sizeof(data) = " << sizeof(data) << endl;
}
//传数组 用模板
template<class T, size_t Size>
void TestMenArr(T (&data)[Size]) {
    cout << "template sizeof(data) = " << sizeof(data) << endl;
}
//指针的输出  1.修改原内存  2.使用函数内创建的内存
void TeseMen() {
    //不能释放栈中空间
    char buf[1024] = "test";
}
void TeseMen(char *out) {
    //出括号无效 修改了局部变量
    out = new char[1024];
}
// 传递数组      √√√√√√√
int TeseMen(char **out) {
    //正确
    int size = 1024;
    *out = new char[size];
    return size;
}

//智能指针作为参数传递
class Data {
public:
    Data() { cout << "(Data)" << endl; }
    virtual ~Data() {
        cout << "~(Data)" << endl;
    }
    int index = 0;
protected:
};
//智能指针作为参数传递

unique_ptr<Data> TestUnique(unique_ptr<Data> ptr) {
    cout << "ptr1 ->index in " << ptr->index << endl;
    unique_ptr<Data> re;
    return re;
}
//智能指针作为参数传递

unique_ptr<Data> TestUnique1(unique_ptr<Data> ptr) {
    cout << "ptr1 ->index in " << ptr->index << endl;
    unique_ptr<Data> re(new Data);
    re->index =333;
    return re;
}
int main() {
    char data[] = "test mem ptr";
    PtrFunction(data, sizeof(data));
    PtrFunction(data);
    TestMenArr(data);
    char *out = nullptr;
    TeseMen(&out);
    cout << "out " << (int) *out << endl;
    delete out;
    cout << "=====================" << endl;
    unique_ptr<Data> ptr1(new Data);
    ptr1->index = 111;
    cout << "ptr1 ->index " << ptr1->index << endl;
    TestUnique(move(ptr1));
    if (!ptr1) {
        cout << "empty" << endl;
    } else {
        cout << "ptr1 ->index " << ptr1->index << endl;
    }
    cout << "=====================" << endl;

    unique_ptr<Data> ptr2(new Data);
    auto re = TestUnique1(move(ptr2));
    cout << "ptr1 ->index == " << re->index << endl;

    return 0;
}