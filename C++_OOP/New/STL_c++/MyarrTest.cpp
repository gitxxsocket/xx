//
//

#include <iostream>
#include <string>
#include <vector>
#include "Myarr.hpp"
using namespace std;

int main() {
    Array<int,5> myIntArr;
    for (int i = 0; i < myIntArr.size(); ++i) {
        myIntArr.set(i*10,i);
        cout << ""<<myIntArr[i] << endl;
    }
    return 0;
}