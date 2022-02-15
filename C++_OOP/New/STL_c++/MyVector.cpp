//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class Ty>
class MyVector {
public:
    typedef Ty* viter;
    typedef Ty value;
    MyVector(int nLen = 0) : m_nLen{nLen}, m_Data(nullptr), finish(0) {
        if (nLen > 0) {
            m_Data = new Ty[nLen];
            start = m_Data;
            end_of_element = nLen;
        }
    }
    virtual ~MyVector() {
        delete[] m_Data;
    }
    void push_back(const value &x) {
        if (end_of_element != finish) {
            *(start + finish) = x;
            ++finish;
        } else {}
        cout << "越界" << endl;
    }
    inline value pop_back() {
        --finish;
        return *(start + finish);
    }
    value &operator[](int n) {
        if (n == finish || n < finish) {
            return *(start + n);
        } else {
            cout << "取值错误" << endl;
        }
    }
protected:
    viter m_Data;   //数组头指针
    int m_nLen;     //数组长度
    viter start;    //数组的起始地址
    int finish;     //数组的满位标志
    int end_of_element; //数组的末尾标识
};

int main() {
    int x;
    MyVector<int> vec(10);
    vec.push_back(100);
    vec.push_back(200);
    vec.push_back(300);
    vec.push_back(600);
    x = vec.pop_back();
    cout << "x =" << x << endl;
    cout << vec[0] << endl;
    cout << vec[1] << endl;
    cout << vec[2] << endl;
    cout << vec[3] << endl;
    return 0;
}