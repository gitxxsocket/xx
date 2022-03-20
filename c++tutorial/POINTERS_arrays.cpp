#include <iostream>
#include <memory>
using namespace std;
int main() {

    int luckyNumber[5] = {2,3,5,7,9};
    int luckyNumberlist[5] ;
/*    cout<<luckyNumber<<endl;
    cout<<&luckyNumber[0]<<endl;
    cout<<luckyNumber[2]<<endl;
    cout<<*(luckyNumber+2)<<endl;*/
    for (int i = 0; i < 4; ++i) {
        cout<<"Number: ";
        cin>>luckyNumberlist[i];
    }
    for (int i = 0; i < 5; ++i) {
        cout<<*(luckyNumberlist+i)<<"  ";
    }
    return 0;
}
