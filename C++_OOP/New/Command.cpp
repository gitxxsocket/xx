//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Light {
public:
    void on() { cout << " turn on " << endl; }
    void off() { cout << " turn off " << endl; }
protected:
};

class Command {
public:
    virtual void execute() = 0;
    virtual void undo() = 0;
protected:
    Command() {}
};

class LightOnCommand : public Command {
    Light *m_pLight;
public:
    LightOnCommand(Light *mPLight) : m_pLight(mPLight) {}
    void execute() override {
        m_pLight->on();
    }
    void undo() override {
        m_pLight->off();
    }
protected:
};

class LightOffCommand : public Command {
    Light *m_pLight;
public:
    LightOffCommand(Light *mPLight) : m_pLight(mPLight) {}
    void execute() override {
        m_pLight->on();
    }
    void undo() override {
        m_pLight->on();
    }
protected:
};

class NoCommand : public Command {
public:
    void execute() {}
    void undo() {}
protected:
};

class SimpleRemoteControl {
public:
    void setMPCommand(Command *mPCommand) {
        m_pCommand = mPCommand;
        m_pUndoCommand = new NoCommand;
    }
    /*void buttonPressed() {
        m_pCommand->execute();
    }*/


    void offButtonWasPushed() {
        m_pCommand->execute();
        m_pUndoCommand = m_pCommand;
    }
    void undoButtonWasPushed() {
        m_pUndoCommand->undo();
        m_pUndoCommand = m_pCommand;

    }
protected:
private:
    Command *m_pCommand;
    //增加Undo撤销的能力
    Command *m_pUndoCommand;
};

int main() {
    auto pControl = new SimpleRemoteControl;
    auto pLight = new Light();
    auto pOnCommand = new LightOnCommand(pLight);
    pControl->setMPCommand(pOnCommand);
    pControl->offButtonWasPushed();
//    pControl->undoButtonWasPushed();
    auto poffCommand = new LightOffCommand(pLight);
    pControl->setMPCommand(poffCommand);
    pControl->offButtonWasPushed();
    pControl->undoButtonWasPushed();

    return 0;
}