#include <iostream>
#include <stdio.h>
#include <string>
#include <map>
using namespace std;


class ExportFileApi{
    public:
        virtual bool exportData(string data) =0 ;

    protected:
        ExportFileApi(){}
};

class ExportTextFile: public ExportFileApi{
    public:
        bool exportData(string data){
            cout<<" ExportTextFile..."<<data<<".data......"<<endl;
            return true;
        }};
class ExportDB: public ExportFileApi{
    public:
        bool exportData(string data){
            cout<<" ExportDB..."<<data<<".data......"<<endl;
            return true;
        }
};

class ExportOperate{
    public:
        bool exportData(string data){
            ExportFileApi* pApi = factoryMethod();
            return pApi->exportData(data);
        }
    protected:
        virtual ExportFileApi* factoryMethod()=0;
};

class ExportFileOperate:public ExportOperate{
protected:
    ExportFileApi* factoryMethod(){
        return new ExportTextFile();
    }

};

class ExportDBOperate :public ExportOperate{
    protected:
    ExportFileApi* factoryMethod(){
        return new ExportDB();
    }
};

int main(void){

    ExportOperate* pOperate = new ExportFileOperate();
    pOperate->exportData("xxxxxxxx");
    return 0;
}