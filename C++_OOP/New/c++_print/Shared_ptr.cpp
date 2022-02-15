//
//

#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Data {
public:
    Data() {
        cout << " shared_ptr class Data construct" << endl;
    }
    virtual ~Data() {
        cout << " shared_ptr class Data ~unconstruct" << endl;
    }

    int index1 =1;
    int index2 =2;
protected:
};

void DelData(Data *p) {
    cout << " DelData ~~~~~~ " << endl;
    delete p;
}
int main() {
    {
        shared_ptr<int> sp1(new int);
        shared_ptr<int[]> sp2(new int[1024]);
        *sp1 = 10;
        sp2[0] = 100;
        auto d1 = sp1.get();
        auto sp3 = make_shared<Data>();
        cout << "sp3.use_count = " << sp3.use_count() << endl;

        //可以复制 构造
        auto sp4 = sp3;
        cout << " sp4 sp3.use_count = " << sp3.use_count() << endl;
        auto sp5 = make_shared<Data>();
        sp4 = sp5;
        cout << " sp5 sp4 sp3.use_count = " << sp3.use_count() << endl;
        sp3.reset();
        {
            auto sp6 = sp3;
            cout << " sp6 sp5 sp4 sp3.use_count = " << sp3.use_count() << endl;
        }
        cout << " } sp5 sp4 sp3.use_count = " << sp3.use_count() << endl;
        sp3.reset(); //手动释放 用函数指针

        {
            //shared_ptr 定制删除函数
            shared_ptr<Data> sp7(new Data, DelData);
        }
        {
            shared_ptr<Data> sp8(new Data,[](auto  p ){
                cout << " lambda..............." << endl;
                delete p ;
            });
        }
        {
            //shared_ptr 指向同一个对象 不同成员
            shared_ptr<Data> sc1(new Data);
            cout << "shared_ptr<Data> sc1 " << sc1.use_count()<<endl;
            shared_ptr<int> sc2(sc1,&sc1->index2);
            shared_ptr<int> sc3(sc1,&sc1->index1);
            cout << "shared_ptr<Data> sc1 " << sc1.use_count()<<endl;

        }
        cout << "=====================================" << endl;
        {
            //shared_ptr 解决循环引用

            //weak_ptr

            class B;
            class A{
            public:
                A() { cout << "A()" << endl;}
                virtual ~A() {cout << "~A()" << endl;
                }
                weak_ptr<B> b1;

            };
            class B{
            public:
                B() {cout << "B()" << endl;}
                virtual ~B() {cout << "~B()" << endl;
                }
                weak_ptr<A> a1;

            };
            auto a = make_shared<A>();
            auto b = make_shared<B>();
            a->b1 =b;
            cout << " use_count = " <<b.use_count()<< endl;
            b->a1 =a;
            cout << " use_count = " <<a.use_count()<< endl;

        }
    }
    return 0;
}