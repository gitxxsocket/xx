//
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Data {
public:
    static int index;
    Data() {
        index++;
        cout << index << this << "  class Data construct" << endl;
    }
    virtual ~Data() {
        cout << index << "  class Data ~unconstruct" << endl;
    }
protected:
};

struct AVPacket {
    unsigned char *data = nullptr;
    int size = 0;
};

class PacketDelete {
public:
    void close() {
        cout << "..PacketDelete struct ...." << endl;
    }
    /////////////////////////////////////////////////////////
    void operator()(AVPacket *p) const {  //const 在函数里不修改对应的内容
        cout << "  ..void operator()(AVPacket *p)const{  ...." << endl;
        delete p;
    }
protected:
};

int Data::index = 0;
int main() {
    {
        //RAII
        unique_ptr<int> p1(new int);
        unique_ptr<Data> p2(new Data);
        cout << "==========" << endl;
        auto p3 = make_unique<Data>();

        //空智能指针
        unique_ptr<Data>(p4);
        unique_ptr<int[]>(pa1) = make_unique<int[]>(1024);
        unique_ptr<int[]> p5(new int[2048]);
        unique_ptr<Data[]> p6(new Data[3]);
    }
    {
        //智能指针访问方式 数组
        unique_ptr<int[]> pp1(new int[1024]);
        pp1[1] = 100;
        pp1[0] = 1;
        cout << "" << pp1[0] << endl;

        //
        auto d1 = new Data();
        unique_ptr<Data> pp5(d1);
        cout << "pp5 = " << pp5 << endl;
        cout << "d1 = " << d1 << endl;
        cout << " " << pp5.get() << endl;
    }
    {
        //重置和移动内存资源 不可复制构造
        // Disable copy from lvalue.
//        unique_ptr(const unique_ptr&) = delete;
//        unique_ptr& operator=(const unique_ptr&) = delete;
        unique_ptr<Data> p6(new Data);

        //支持移动构造 move 释放所有权 转移所有权
        unique_ptr<Data> p7 = move(p6);
        //支持移动赋值
        unique_ptr<Data> p8(new Data);
        p7 = move(p8);

        //重置空间 原空间清理
        p7.reset(new Data);

        //释放所有权和定义空间删除
        p7 = nullptr;
        //手动释放
        unique_ptr<Data> p9(new Data);
        auto pData9 = p9.release();
        delete pData9;


        //自定义空间删除方法  .本身的函数 ->指向对象
        unique_ptr<AVPacket, PacketDelete> p10(new AVPacket);
        unique_ptr<AVPacket, PacketDelete> p11(new AVPacket);
        p11.get_deleter().close();
        p11.get_deleter()(p11.get());
        p11.release();
    }
    return 0;
}