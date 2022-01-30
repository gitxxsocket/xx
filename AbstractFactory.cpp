#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
#include <memory>
#include <functional>
using namespace std;

class FrameApi{
    public:
        virtual void draw() = 0;
    protected:
        FrameApi(){}
};

class layoutApi{
    public:
        virtual void installFrame() = 0;
    protected:
        layoutApi(){}
};

class ComputerFrame: public FrameApi{

        int m_pins;

    public:
        ComputerFrame(int pins):m_pins(pins){}

        void draw(){
            cout<< "ComputerFrame"<<m_pins<<end;
        }
    
};

class MobileFrame: public FrameApi{
    int  m_pins;
    public:
        MobileFrame(int pins):m_pins(pins){}
        void draw(){
            cout<< "MobileFrame"<<m_pins<<end;

        }
};

class HighLayout:public  layoutApi{

    int m_FrameAdapterPins;
    public:
        HighLayout(int FrameAdapterPins):m_FrameAdapterPins(FrameAdapterPins){}
        void installFrame(){
            cout<<"HighLayout"<<m_FrameAdapterPins<<endl;
        }
};

class LowLayout:public  layoutApi{

    int m_FrameAdapterPins;
    public:
        LowLayout(int FrameAdapterPins):m_FrameAdapterPins(FrameAdapterPins){}
        void installFrame(){
            cout<<"LowLayout"<<m_FrameAdapterPins<<endl;
        }
};



class FrameFactory{
    static FrameApi* createFrame(int type){
        if (type ==1) 
        return new ComputerFrame(1024);
        
         if (type ==2) 
        return new ComputerFrame(800);
        
        return nullptr;
    }
};


class LayoutFactory{
    public:
        static layoutApi* createLayout(int type){
             if (type == 1) 
                return new HighLayout(1024);
             if (type == 2) 
                return new LowLayout(800);
        return nullptr;

        }
};

class GUIEnginner{
    FrameApi* pFrame;
    layoutApi* pLayout;
    public:
        void prepareDraw( int FrameType,int LayoutType){
                this->pFrame = FrameFactory::createFrame(FrameType);
                this->pLayout = LayoutFactory::createFrame(LayoutType);
                pFrame->draw();
                pLayout->installFrame();
        }
};

int main(void){
    GUIEnginner * pEng = new GUIEnginner;
    pEng->prepareDraw(1,1);
    return 0;
}