#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <stdio.h>
#include <string>
#include <vector>

using namespace std;


class Obsever {
public:
  virtual void update(string m_Temp, string m_Humi) = 0;

protected:
  Obsever() {}
};

//抽象一个Subject主题
class Subject {
public:
  virtual void registerObserver(Obsever *pObj) = 0;
  virtual void removeObserver(Obsever *pObj) = 0;
  virtual void noitfyObserver() = 0;

protected:
  Subject() {}
};

class WeatherData : public Subject {

  vector<Obsever *> m_observers;
  string m_Temp;
  string m_Humi;

public:
    WeatherData(string Temp,string Humi):m_Temp(Temp),m_Humi(Humi){}

  void registerObserver(Obsever *pObj) { m_observers.push_back(pObj); }
  void removeObserver(Obsever *pObj) {
    auto iter = find(m_observers.begin(), m_observers.end(), pObj);
    if (iter != m_observers.end()) {
      m_observers.erase(iter);
    }
  }
  void noitfyObserver() {
      for(vector<Obsever*>::iterator iter = m_observers.begin();iter!=m_observers.end();iter++){
          (*iter)->update(m_Temp,m_Humi);
      }

  }

  void setData(string Temp,string Humi){
      string m_Temp =Temp;
      string m_Humi =Humi;
      noitfyObserver();
  }
};

class PCDisplay : public Obsever {
  WeatherData *m_pWeatherData;

public:
  PCDisplay(WeatherData *pWeatherData) {
    m_pWeatherData = pWeatherData;
    m_pWeatherData->registerObserver(this);
  }

  void update(string m_Temp, string m_Humi) {
    cout << "我是PC端显示的 当前的温度为:   " << m_Temp
         << "湿度是:   " << m_Humi << endl;
  }
};

class MobileDisplay : public Obsever {
  WeatherData *m_pWeatherData;

public:
  MobileDisplay(WeatherData *pWeatherData) {
    m_pWeatherData = pWeatherData;
    m_pWeatherData->registerObserver(this);
  }

  void update(string m_Temp, string m_Humi) {
    cout << "我是Mobile端显示的 当前的温度为:   " << m_Temp
         << "湿度是:   " << m_Humi << endl;
  }
};

int main(void) {
        WeatherData* pWD= new WeatherData("22","60%");
        PCDisplay* pPCDisplay=new PCDisplay(pWD);
        pWD->setData("38","70%");
     return 0; }

/*
class WeatherData {

  string m_Pressusre;
  string m_Tempturare;
  string m_Hummnity;

  MobileDisplay *m_pMoblie;
  PCDisplay *m_PCDisplay;

public:
  void mearueDataChange() {
    m_pMoblie->update(m_Pressusre, m_Tempturare, m_Hummnity);
    m_PCDisplay->update(m_Pressusre, m_Tempturare, m_Hummnity);
  }
};

class MobileDisplay {
public:
  void update(string strpressure, string strTempturare, string strHummnity) {
    cout << "   压力是   " << strpressure << "温度是" << strTempturare
         << "湿度是" << strHummnity << endl;
  }
};

class PCDisplay {
public:
  void update(string strpressure, string strTempturare, string strHummnity) {
    cout << "   压力是   " << strpressure << "温度是" << strTempturare
         << "湿度是" << strHummnity << endl;
  }
};

int main(void) { return 0; }
*/