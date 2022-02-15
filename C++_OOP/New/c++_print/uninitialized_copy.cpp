//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Data {
public:
    Data() { cout << "(Data)" << endl; }
    Data(const Data &d) { cout << "(Data(const Data &d))" << endl; }
    Data &operator=(const Data &d) {
        this->index = d.index;
        cout << " operator=  " << index << endl;
        return *this;
    }
    virtual ~Data() {
        cout << "~(Data)" << endl;
    }
    int index = 0;
};

int main() {
    Data datas[3];
    unsigned char buf[1024] = {0};
    cout << "=======memcpy===========" << endl;
    auto c1 = memcpy(buf, &datas, sizeof(datas));
    cout << "========std::copy==========" << endl;
    auto c2 = std::copy(std::begin(datas), std::end(datas), (Data *) (buf));
    cout << "========uninitialized_copy==========" << endl;
    auto c3 = uninitialized_copy(begin(datas), end(datas), (Data *) buf);
    cout << "=================================" << endl;
    {
        //C++20 construct_at destory
        cout << "==========construct_at=======================" << endl;
        int size = 3;
        auto data = static_cast<Data *>( malloc(sizeof(Data) * size));
        for (int i = 0; i < size; ++i) {
            if(data)
            construct_at(&data[i]);

        }
        destroy(data,data+size);
        free(data);
    }
    return 0;
}