#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <memory>
#include <functional>
using namespace std;


template <class T>

class IocContainer{

    map<string,std::function<T* ()>> m_createMap;

    void RegisterType(string strKey,std::function<T* ()> creator){
        if(m_createMap.find(strKey)!= m_createMap.end()){
            throw std::invalid_argument("  !!");
        }
        m_createMap.emplace(strKey,creator);
    }
    public:
        IocContainer(){}
        ~IocContainer(){}

        template<class Drived>
        void RegisterType(string strKey){
            std::function<T* ()> function = [] {return new Drived();};
            RegisterType(strKey,function);
        }

        T* Resolve(string strKey){
            if (m_createMap.find(strKey) == m_createMap.end())
            return nullptr;
            std::function<T* ()> function = m_createMap[strKey];
            return function();
        }
        std::shared_ptr<T> ResolveShared(string strKey){
            T* ptr = Resolve(strKey);
            return std::shared_ptr<T>(ptr);
        }

};

struct ICar{
    virtual ~ICar(){}
    virtual void test() const =0;

};

struct Bus:ICar{
    Bus(){}
    void test( )const {
        std::cout<<"buss";
    }
};

struct Track:ICar{
    Track(){};
    void test( )const{
        std::cout<<"Track";
        
    }
};

int main(void){
    IocContainer<ICar> carIOC;
    carIOC.RegisterType<Bus>("bus");
    carIOC.RegisterType<Track>("track");
    std::shared_ptr<ICar> bus = carIOC.ResolveShared("bus");
    bus->test();
    std::shared_ptr<ICar> track = carIOC.ResolveShared("track");
    track->test();
}
 