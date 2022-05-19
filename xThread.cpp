//
#pragma once
#include <thread>

class XThread
{
private:
    virtual void Main() = 0;
    bool is_exit_ = false;
    std::thread th_;
public:

    virtual void Start();
    virtual void Stop();
    virtual void Wait();
    bool is_exit();
};

//

 #include "xthread.h"
using namespace std;

     void XThread::Start(){
         is_exit_ =false;
         th_ = thread(&XThread::Main,this); 
     }
     void XThread::Stop(){
         is_exit_ = true;
         Wait();
     }
     void XThread:: Wait(){
         if (th_.joinable())
         {
             th_.join();
         }
         
     }  
    bool XThread::is_exit(){
        return is_exit_;
    }

//
#pragma once
#include "xthread.h"
#include <string>
#include <vector>
#include <mutex>
class XMsgServer :public XThread
{
private:
    virtual void Main() override;
    std::vector<std::string> msgs_;
    std::mutex mux_;
public:
    void SendMsg(std::string msg);
};

//
#include "xmsg_server.h"
#include <iostream>
using namespace std;
using namespace this_thread;

 // namespace std;
void XMsgServer:: Main() {
    while (!is_exit())
    {
        sleep_for(10ms);
        unique_lock<mutex> lock(mux_);
        if(msgs_.empty())
            continue;
        while (!msgs_.empty())
        {
            cout<<"recv: "<<msgs_.front()<<endl;
            msgs_.pop_back();
        }
        
    }
    
}


void XMsgServer:: SendMsg(std::string msg)
{
    unique_lock<mutex> lock(mux_);
    msgs_.push_back(msg);

}


//
#include "xmsg_server.h"
#include "xthread.h"
#include <sstream>
using namespace std;
int main(){
    XMsgServer server;
    server.Start();
    for (size_t i = 0; i < 10; i++)
    {
        stringstream ss;
        ss<< "  msg : "<< i +1 ;
        server.SendMsg(ss.str());
        this_thread::sleep_for(500ms);

    }
    server.Stop();
    
}
