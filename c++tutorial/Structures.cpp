#include <iostream>
#include <memory>

using namespace std;

struct Smartphone {
    string name;
    int storageSpace;
    string color;
    float price;
};

struct Person {
    string name;
    int age;
    Smartphone smartphone;
};

void printSmartPhoneInfo(Smartphone mysmartphone) {
    cout << "name: " << mysmartphone.name << endl;
}

void printPersonInfo(Person person){
    cout << "name: " << person.name << endl;
    cout << "age: " << person.age << endl;
    printSmartPhoneInfo(person.smartphone);
}

int main() {
    Smartphone smartphone;
    smartphone.name = "iPhone 12";
    smartphone.storageSpace = 32;
    smartphone.color = "black";
    smartphone.price = 999.99;
    smartphone.name = "iPhone 12";

    Smartphone smartphone2;
    smartphone2.name = "iPhone 11";
    smartphone2.storageSpace = 64;
    smartphone2.color = "gray";
    smartphone2.price = 888.99;

    Person p;
    p.name = "Saldina";
    p.age = 26;
    p.smartphone = smartphone2;
    printPersonInfo(p);
    return 0;
}
