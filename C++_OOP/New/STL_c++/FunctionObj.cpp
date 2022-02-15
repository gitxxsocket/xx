//
//仿函数

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
class Add{
public:
    int operator()(int a,int b){
        return a+b+m_x;
    }
private:
    int m_x;
public:
    Add(int temp) : m_x(temp) {}
};

using namespace std;
int main() {
    vector<int> myVec;
    sort(myVec.begin(), myVec.end(),greater<int>());

    Add myAdd(100);
    cout << myAdd(1,2) << endl;
    Add myAdd2(200);
    cout << myAdd2(1,2) << endl;

    //greater<int>() 调用()重载对象 重载某个运算改变对象外观
    return 0;
}