//
//  状态

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class DownloadManager;

class DownloadState {
public:
    virtual void Down(string User, string DownItem, DownloadManager *p) = 0;
protected:
    DownloadState() {}
};

class NormalDownState : public DownloadState {
public:
    void Down(string User, string DownItem, DownloadManager *p) override {
        cout << "Welcome Download doing..." << endl;
    }
protected:
};

class RepeateDownState : public DownloadState {
public:
    void Down(string User, string DownItem, DownloadManager *p) override {
        cout << "Repeate download Cancel..." << endl;
    }
protected:
};

class SpiteDownState : public DownloadState {
public:
    void Down(string User, string DownItem, DownloadManager *p) override {
        cout << "Spite Download ..." << endl;
    }
protected:
};

class blackDownState : public DownloadState {
public:
    void Down(string User, string DownItem, DownloadManager *p) override {
        cout << "black downloads Cancel..." << endl;
    }
protected:
};

class DownloadManager {
public:
    const map<string, string> &getMMapDown() const {
        return m_mapDown;
    }
    void Down(string User, string DownItem) {
        int oldDownCount = 0;
        if (m_mapDownCount.count(User) > 0) {
            oldDownCount = m_mapDownCount[User];
        } else {
            m_mapDownCount[User] = 0;
        }
        oldDownCount++;
        m_mapDownCount[User] = oldDownCount;
        if (oldDownCount == 1) {
            m_pDownloadState = new NormalDownState();
        } else if (oldDownCount > 1 && oldDownCount < 3) {
            m_pDownloadState = new RepeateDownState();
        } else if (oldDownCount > 3 && oldDownCount < 5) {
            m_pDownloadState = new SpiteDownState();
        } else if (oldDownCount >= 5) {
            m_pDownloadState = new blackDownState();
        }
        m_pDownloadState->Down(User, DownItem, this);
    }
public:
    map<string, string> m_mapDown;
    map<string, int> m_mapDownCount;
private:
    DownloadState *m_pDownloadState;
};

int main() {
    auto pManager = new DownloadManager;
    for (int i = 0; i < 1; ++i) {
        pManager->Down("dst", "c++");
    }
    return 0;
}