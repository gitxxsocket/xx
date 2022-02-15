#include <iostream>
#include <string>
using namespace std;

//访问者
//      连个多态:accpt,visit
//双重分发   使你可以在改变个元素的类的前提下定义作用于这些元素的新操作
//案例:   工单系统

class Xiaomi;

class Vivo;

class Oppo;

class CellPhoneVisitor {
public:
    virtual void visit(Xiaomi *pXiaomi) = 0;
    virtual void visit(Vivo *pVivo) = 0;
    virtual void visit(Oppo *pOppo) = 0;
//    virtual void accept(CellPhoneVisitor *CellPhoneVisitor) = 0;
protected:
    CellPhoneVisitor() {}
};

class CellPhone {
public:
    virtual void dial() = 0;
    virtual void sendMsg() = 0;
    virtual void recvMsg() = 0;
    virtual void hang() = 0;
protected:
    CellPhone() {}
};

class Xiaomi : public CellPhone {
public:
    void dial() { cout << "Xiaomi  " << "dial()..." << endl; }
    void sendMsg() { cout << "Xiaomi  " << "sendMsg()..." << endl; }
    void recvMsg() { cout << "Xiaomi  " << "recvMsg()... " << endl; }
    void hang() { cout << "Xiaomi  " << "hang()..." << endl; }
    void accept(CellPhoneVisitor *CellPhoneVisitor) {
        CellPhoneVisitor->visit(this);
    }
protected:
};

class Vivo : public CellPhone {
public:
    void dial() { cout << "Vivo    " << "dial()..." << endl; }
    void sendMsg() { cout << "Vivo    " << "sendMsg()..." << endl; }
    void recvMsg() { cout << "Vivo    " << "recvMsg()... " << endl; }
    void hang() { cout << "Vivo    " << "hang()..." << endl; }
    void accept(CellPhoneVisitor *CellPhoneVisitor) {
        CellPhoneVisitor->visit(this);
    }
protected:
};

class Oppo : public CellPhone {
public:
    void dial() { cout << "Oppo  " << "dial()..." << endl; }
    void sendMsg() { cout << "Oppo  " << "sendMsg()..." << endl; }
    void recvMsg() { cout << "Oppo  " << "recvMsg()... " << endl; }
    void hang() { cout << "Oppo  " << "hang()..." << endl; }
    void accept(CellPhoneVisitor *CellPhoneVisitor) {
        CellPhoneVisitor->visit(this);
    }
protected:
};

class SolarisConfigure : public CellPhoneVisitor {
public:
    void visit(Xiaomi *p) override {
        p->dial();
        p->hang();
        p->sendMsg();
        p->recvMsg();
    }
    void visit(Vivo *p) override {
        p->dial();
        p->hang();
        p->sendMsg();
        p->recvMsg();
    }
    void visit(Oppo *p) override {
        p->dial();
        p->hang();
        p->sendMsg();
        p->recvMsg();
    }
protected:
};

int main() {
    CellPhoneVisitor *pVisitor = new SolarisConfigure;
    auto pXiaomi = new Xiaomi;
    auto pVivo = new Vivo;
    auto pOppo = new Oppo;
    //回调对象
    pXiaomi->accept(pVisitor);
    pVivo->accept(pVisitor);
    pOppo->accept(pVisitor);
    return 0;
}