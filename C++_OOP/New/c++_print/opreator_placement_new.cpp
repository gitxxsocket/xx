//
//
// 重载new 和 delete
// 检测内存创建销毁 统计监控内存泄露
// 内存对齐
// 多进程内存共享
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//重载全局new
void *operator new(size_t size) {
    cout << " *operator new " << endl;
    auto mem = malloc(size);
    return mem;
    if (!mem) {
        throw std::bad_alloc();
    }
}
void *operator new[](size_t size) {
    cout << " *operator new[] " << endl;
    auto mem = malloc(size);
    if (!mem) {
        throw std::bad_alloc();
    }
    return mem;

}
void operator delete(void *ptr) {
    cout << " operator delete " << endl;
    std::free(ptr);
}
void operator delete[](void *ptr) {
    cout << " operator delete []" << endl;
    std::free(ptr);
}

class TestMen {
public:
    TestMen() { cout << "(TestMen)" << endl; }
    virtual ~TestMen() {
        cout << "~(TestMen)" << endl;
    }
    void *operator new(size_t size ) {
        cout << "(TestMen)  *operator new " <<size<< endl;
        auto mem = malloc(size);
        if (!mem) {
            throw std::bad_alloc();
        }
        
        //
        void *operator new (size_t size,void *ptr){
            cout << "placement new" << endl;
            return ptr;
        }

        return mem ;

    }
protected:
};

int main() {
//    auto pMen1 = new TestMen;
//    delete pMen1;
//    auto arr1 = new int[1024];
//    delete[] arr1;
    auto pMen = new TestMen;
    delete  pMen;
    cout << "=================" << endl;
    int buf1 [1024] = {0};
    TestMen *mem1 = ::new(buf1) TestMen;

    int* buf2 = new int[1024]{0};
    auto mem3 =::new(buf2) TestMen;
    delete mem3;
    
    
    int* buf3 =new int[1024]{0};
    auto mem4 = new(buf3) TestMen;

    return 0;
}