//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Test1;

class Test2;

template<class T>
class TypeTb1 {
};

template<>
class TypeTb1<Test1> {
public:
    typedef char ret_type;
    typedef int par1_type;
    typedef double par2_type;
};

template<>
class TypeTb1<Test2> {
public:
    typedef double ret_type;
    typedef double par1_type;
    typedef int par2_type;
};

template<typename T>
class Test {
public:
    typename TypeTb1<T>::ret_type compute(typename TypeTb1<T>::par1_type x,
                                          typename TypeTb1<T>::par2_type y) {
        return  x+y;}
};

int main(){
    Test<Test1> t1;
    cout<<t1.compute(66,6.18)<<endl;
    return 0;
}