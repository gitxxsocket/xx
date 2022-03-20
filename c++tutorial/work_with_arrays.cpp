#include <iostream>
#include <memory>
using namespace std;
int main() {
    int size;
    cin>>size;
    float monthsArray[size];

    float total = 0 ;
    for (int i = 0; i < size; ++i) {
        cout<< "Enter amount for month "<<i+1<<": ";
        cin>> monthsArray[i];
        total += monthsArray[i];
    }

    float average = total /6 ;
    float  inTwoYears = average *25;

    cout<<"total =  "<< total<<endl;
    cout<<"average =  "<< average<<endl;
    cout<<"inTwoYears =  "<< inTwoYears<<endl;
    return 0;
}
