//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<class _A1,class _A2,class _R>
struct binary{
    typedef _A1 Arg1;
    typedef _A2 Arg2;
    typedef _R Rtn;
};

template<class TR,class T1,class T2>
class Add : public  binary <TR,T1,T2> {
public:
    TR bFunction(const T1& x,const T2& y)const{
        return x+y;
    }
protected:
};

int main() {

    double a =100.01,b= 20.2;
    Add<double,double,double> addObj;
    typename Add<int,int,double>::Arg1  x =1000;
    return 0;
}