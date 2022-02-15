//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

//分配器allocator
//对象内存分配  和 构造分离

class Data {
public:
    Data() { cout << "(Data)" << endl; }
    virtual ~Data() {
        cout << "~(Data)" << endl;
    }
    int index1 = 1;
    int index2 = 2;
    Data(const Data &d) {
        this->index1 = d.index1;
        cout << "(Data(const Data &d))" << index1 << endl;
    }
};

template<class Ty>
class MyAllocator {
public:
    MyAllocator() {}
    template<class Other>
    MyAllocator(const MyAllocator<Other> &) {}
    using value_type = Ty;
    void deallocate(Ty *const ptr, const size_t count) {
        cout<< typeid(Ty).name()<<endl;
        free(ptr);
    }
    Ty *allocate(const size_t count) {
        cout << "" << endl;
        return static_cast<Ty *>(malloc(sizeof(Ty) * count));
    }
};

int main() {
    allocator<Data> Data_alloc;
    int size = 3;
    auto dataarr = Data_alloc.allocate(size);
    for (int i = 0; i < size; ++i) {
        allocator_traits<decltype(Data_alloc)>::construct(Data_alloc, &dataarr[i]);
        allocator_traits<decltype(Data_alloc)>::destroy(Data_alloc, &dataarr[i]);
    }
    Data_alloc.deallocate(dataarr, size);
    cout << "===================================" << endl;
    //自定义分配器
    vector<Data, MyAllocator<Data>> vd;
    Data d;
    d.index1 = 111;
    vd.push_back(d);
    d.index1 = 222;
    vd.push_back(d);
    d.index1 = 333;
    vd.push_back(d);
    for (auto &xd: vd) {
    }
    return 0;
}