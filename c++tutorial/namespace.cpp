#include <iostream>
#include <memory>
using namespace std;


namespace namespace1  {
    int age = 25;
}
namespace namespace2  {
    int age = 26;

}
int main() {
    cout<<namespace1::age;
    cout<<namespace2::age<<endl;
    return 0;
}
