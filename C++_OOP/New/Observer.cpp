//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Observer;

class Subject {
public:
    virtual void registerObserver(Observer *o) = 0;
    virtual void removeObserver(Observer *o) = 0;
    virtual void noitfyObserver() = 0;
protected:
    Subject() {}
};

class Observer {
public:
    virtual void update(string m_Temp, string m_Humi) = 0;
protected:
    Observer() {}
};

class WeatherData : public Subject {
public:
    WeatherData(const string &mTemp, const string &mHumi) : m_Temp(mTemp), m_Humi(mHumi) {}
    void registerObserver(Observer *o) override {
        m_observer.push_back(o);
    }
    void removeObserver(Observer *o) override {
        auto iterator = find(m_observer.begin(), m_observer.end(), o);
        if (iterator != m_observer.end()) {
            m_observer.erase(iterator);
        }
    }
    void noitfyObserver() override {
        for (vector<Observer *>::iterator iter = m_observer.begin(); iter != m_observer.end(); iter++) {
            (*iter)->update(m_Temp, m_Humi);
        }
    }
    void setMTemp(const string &mTemp, const string &mHumi) {
        m_Temp = mTemp;
        m_Humi = mHumi;
        noitfyObserver();
    }
protected:
private:
    vector<Observer *> m_observer;
    string m_Temp;
    string m_Humi;
};

class PCDisplay : public Observer {
public:
    void update(string m_Temp, string m_Humi) override {
        cout << "PCDisplay ........." << m_Temp << "   " << m_Humi << endl;
    }
    PCDisplay(WeatherData *mPWeatherData) : m_pWeatherData(mPWeatherData) {
        m_pWeatherData = mPWeatherData;
        m_pWeatherData->registerObserver(this);
    }
private:
    WeatherData *m_pWeatherData;
protected:
};

class MobileDisplay : public Observer {
public:
    void update(string m_Temp, string m_Humi) override {
        cout << "PCDisplay ........." << m_Temp << "   " << m_Humi << endl;
    }
    MobileDisplay(WeatherData *mPWeatherData) : m_pWeatherData(mPWeatherData) {
        m_pWeatherData = mPWeatherData;
        m_pWeatherData->registerObserver(this);
    }
private:
    WeatherData *m_pWeatherData;
protected:
};

int main() {
    auto pWeatherData = new WeatherData{"1","2"};
    auto pPcDisplay = new PCDisplay(pWeatherData);

    pWeatherData->setMTemp("10","11");

    return 0;
}