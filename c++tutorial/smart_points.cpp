//
// Created by admmm on 3/19/2022.
//

#include <iostream>
#include <memory>

using namespace std;

class MyClass {
public:
    MyClass() {
        cout << "Constructor invoked" << endl;
    }

    ~MyClass() {
        cout << "Destructor invoked" << endl;
    }
};

int main() {

    auto unPtr1 = make_unique<int>(25);
    cout << unPtr1 << endl;
    cout << *unPtr1 << endl;
    auto unPtr2 = move(unPtr1);
    cout << unPtr2 << endl;
    cout << *unPtr2 << endl;
    std::cout << "----------------!" << std::endl;
    { auto myClassPtr1 = make_unique<MyClass>(); }
    std::cout << "----------------!" << std::endl;
    {
        auto shmyClassPtr1 = make_shared<MyClass>();
        std::cout << "Shared count: " << shmyClassPtr1.use_count() << std::endl;
        auto shmyClassPtr2 = shmyClassPtr1;
        std::cout << "Shared count: " << shmyClassPtr1.use_count() << std::endl;
        std::cout << "----------------!" << std::endl;

    }

    {
        weak_ptr<int> wePtr11;
        {
            auto shPtr11 = make_shared<int>(26);
            wePtr11 = shPtr11;
        }
    }
    return 0;
}
