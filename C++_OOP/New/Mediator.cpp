//  调停者模式
// 换肤

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Colleague;

//对象在自身改变的情况下 通知Mediator进行变更
class Mediator {
public:
    virtual void changed(Colleague *pColleague) = 0;
protected:
    Mediator() {}
};

class Colleague {
public:
    Colleague() {}
    Colleague(Mediator *mPMediator) : m_pMediator(mPMediator) {}
    Mediator *getMPMediator() const {
        return m_pMediator;
    }
protected:
    Mediator *m_pMediator;
};

class SoundCard : public Colleague {
public:
    SoundCard(Mediator *mPMediator) : Colleague(mPMediator) {}
    void SoundData(string data) {
        cout << "SoundCard doing...." << endl;
    }
protected:
};

class VideoCard : public Colleague {
public:
    VideoCard(Mediator *mPMediator) : Colleague(mPMediator) {}
    void VideoData(string data) {
        cout << "VideoCard doing...." << endl;
    }
protected:
};

class CPU : public Colleague {
public:
    CPU(Mediator *mPMediator) : Colleague(mPMediator) {}
    void executeData(string data[]) {
        cout << "CPU  execute  ...." << endl;
        m_strVideodata = data[0];
        m_strSounddata = data[1];
        this->getMPMediator()->changed(this);
    }
    const string &getMStrVideodata() const {
        return m_strVideodata;
    }
    const string &getMStrSounddata() const {
        return m_strSounddata;
    }
protected:
    string m_strVideodata;
    string m_strSounddata;
};

class MotherBoard : public Mediator{
public:
    void setMPCpu(CPU *mPCpu) {
        m_pCPU = mPCpu;
    }
    void setMPVideoCard(VideoCard *mPVideoCard) {
        m_pVideoCard = mPVideoCard;
    }
    void setMPSoundCard(SoundCard *mPSoundCard) {
        m_pSoundCard = mPSoundCard;
    }
    void changed(Colleague *pColleague) override {
        if (pColleague == m_pCPU) {
            this->openCPU((CPU*)pColleague);
        }
    }
private:
    void openCPU(CPU *pCPU){
        auto strVideoData = pCPU->getMStrSounddata();
        auto strSoundData = pCPU->getMStrVideodata();
        m_pVideoCard->VideoData(strVideoData);
        m_pSoundCard->SoundData(strSoundData);
    }
    CPU *m_pCPU;
    VideoCard *m_pVideoCard;
    SoundCard *m_pSoundCard;
};

int main() {
    //创建调停者
    auto pMotherBoard = new MotherBoard;
    //创建同事类

    auto pCpu = new CPU(pMotherBoard);
    auto pVCard = new VideoCard(pMotherBoard);
    auto pSCard = new SoundCard(pMotherBoard);
    //让Mediator 都知道Colleague的对象
    pMotherBoard->setMPCpu(pCpu);
    pMotherBoard->setMPSoundCard(pSCard);
    pMotherBoard->setMPVideoCard(pVCard);
    string arr[] ={"c++","haha"};
    pCpu->executeData(arr);
    return 0;
}