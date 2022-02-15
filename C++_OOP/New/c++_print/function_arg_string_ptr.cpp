#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;
//void TestString(string data) {
//    cout << "data = "<<data << endl;
//    cout << "data.size() = "<<data.size() << endl;
//    cout << " data addr = "<<(long long )data.data() << endl;
//
//}
void TestString(string &data) {
    cout << "data = " << data << endl;
    cout << "data.size() = " << data.size() << endl;
    cout << " data addr = " << (long long) data.data() << endl;
}
void TestString(string &in_data, string &out_data) {
    cout << "data = " << in_data << endl;
    cout << "data.size() = " << in_data.size() << endl;
    cout << " data addr = " << (long long) in_data.data() << endl;
    out_data.resize(2024);
    cout << " data addr = " << (long long) out_data.data() << endl;
}
int main() {
    string str1;
    str1.resize(1024, 0);
    auto data = const_cast<char *>(str1.data());
    cout << "addr = " << (long long) data << endl;
    memset(data, 'A', 5);
    cout << str1 << endl;
    cout << "-----------------------" << endl;
    TestString(str1);
    cout << "-----------------------" << endl;
    string out_str1;
    TestString(str1, out_str1);
    cout << " data addr = " << out_str1.size() << endl;
    cout << "out_str1.data() addr  " << (long long) out_str1.data() << endl;
    return 0;
}