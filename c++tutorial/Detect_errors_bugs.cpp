#include <iostream>
#include <memory>
using namespace std;
int main() {

    int savedMoney[5] = {100,200,300,400,500};
    int total =0;
    for (int i = 0; i < 5; i++) {
        total += savedMoney[i];
        cout<< "Total: "<<total;
    }
    return 0;
}
