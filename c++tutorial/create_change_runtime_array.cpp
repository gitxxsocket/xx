#include <iostream>
#include <memory>

using namespace std;

int main() {
    int size;
    cout << "Size: ";
    cin >> size;
    int *myArray = new int[size];

    for (int i = 0; i < size; ++i) {
        cout << "Array[" << i << "]";
        cin >> myArray[i];

    }
    for (int i = 0; i < size; ++i) {
        cout << myArray[i] << " "<<endl;
        cout <<"another way "<<*( myArray+i) << " "<<endl;

    }

    delete[]myArray;
    myArray= NULL;
    return 0;
}
