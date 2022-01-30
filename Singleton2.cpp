#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;

class Singleton;
static std::map<string,Singleton*> myMap = std::map<string,Singleton*>();


class Singleton{
    Singleton(){
    m_singer = nullptr;}


    static Singleton *m_singer;
    static string DEFAULT_KEY;

    public:
         static Singleton* getInstance(){
            //std::map<std::string,int>iterator it = myMap.fing(DEFAULT_KEY);
            if(myMap.find(DEFAULT_KEY)!= myMap.end())
            return myMap.find(DEFAULT_KEY)->second;
            if(m_singer == nullptr){
                m_singer = new Singleton;
                myMap[DEFAULT_KEY]= m_singer;
            }
            return m_singer;
    }
};

Singleton *Singleton::m_singer = nullptr;
string Singleton::DEFAULT_KEY = "One";

int main(void){
    Singleton* p1 = Singleton::getInstance();
    Singleton* p2 = Singleton::getInstance();
    cout<<p1<<endl;
    cout<<p2<<endl;
    return 0;
}