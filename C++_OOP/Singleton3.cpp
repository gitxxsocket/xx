#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;


const static int NUM_MAX =5;
class Singleton;
static std::map<int,Singleton*> myMap = std::map<int,Singleton*>();

class Singleton{
    Singleton (){
        m_singer = nullptr;
    }

    static Singleton *m_singer;
            static int m_InstanceCount;


    public:
        static Singleton* getInstance(){
            m_singer = myMap[m_InstanceCount];
            if(m_singer == nullptr){
                m_singer = new Singleton;
                myMap[m_InstanceCount] = m_singer;
            }
            m_InstanceCount++;
            if (m_InstanceCount>NUM_MAX) {
                m_InstanceCount = 1;
            }
            return m_singer;
        }
};


Singleton *Singleton::m_singer = nullptr;
  int Singleton::m_InstanceCount =1;


int main(void){
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    Singleton* p3 = Singleton::getInstance();
    Singleton* p4 = Singleton::getInstance();
    Singleton* p5 = Singleton::getInstance();
    cout<<p1<<endl;
    cout<<p2<<endl;
    cout<<p3<<endl;
    cout<<p4<<endl;
    cout<<p5<<endl;
    return 0;
}