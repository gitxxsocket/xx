//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main() {
    void *ptr1 = malloc(1024);
    free(ptr1);
    int num = 1;
    void *ptr2 = &num;

    //void* 转换
    int *ptr3 = static_cast<int *>(ptr2);
    int *ptr4 = (int *) ptr2;
    const int *cptr1 = new int[1024];
    delete[]cptr1;
    unsigned char *ucptr = new unsigned char[1024];

    //去除const
    auto *ptr5 = const_cast<int *>(cptr1);
    delete[]ucptr;

    //替换指针类型
    auto ptr6 = reinterpret_cast<int *>(ucptr);
    delete ucptr;


    //指针常量  (*pi1)++
    const int i1 = 100;
    const int *pi1 = &i1;
    int const *pi2 = &i1;

    //
    int *const pi3 = new int;
    *pi3 = 200;
    delete pi3;
    const int * const pi4  = &i1;

    //
    return 0;
}