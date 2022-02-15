//
//
//      流式业务
// 责任链

#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template<class T>
string MyConvertToString(T value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

class Handle {
public:
    void setMPHandle(Handle *mPHandle) {
        m_pHandle = mPHandle;
    }
    virtual string handleFeeRequest(double fee) = 0;
protected:
    Handle *m_pHandle;
};

class PrjManager : public Handle {
public:
    string handleFeeRequest(double fee) override {
        string strTemp = "";
        if (fee < 500) {
            strTemp = "PrjHandle agree " + MyConvertToString(strTemp) + " $";
            return strTemp;
        } else {
            if (this->m_pHandle != nullptr) {
                return m_pHandle->handleFeeRequest(fee);
            }
        }
        return strTemp;
    }
};

class DepManager : public Handle {
public:
    string handleFeeRequest(double fee) override {
        string strTemp = "";
        if (fee >= 500 && fee < 1000) {
            strTemp = "DepManager agree " + MyConvertToString(strTemp) + " $";
            return strTemp;
        } else {
            if (this->m_pHandle != nullptr) {
                return m_pHandle->handleFeeRequest(fee);
            }
        }
        return strTemp;
    }
};

class CEO : public Handle {
public:
    string handleFeeRequest(double fee) override {
        string strTemp = "";
        if (fee >= 500 && fee < 1000) {
            strTemp = "CEO agree " + MyConvertToString(strTemp) + " $";
            return strTemp;
        } else {
            if (this->m_pHandle != nullptr) {
                return m_pHandle->handleFeeRequest(fee);
            }
        }
        return strTemp;
    }
};

int main() {
    auto pManager1 = new PrjManager;
    auto pManager2 = new DepManager;
    auto pCeo3 = new CEO;

    pManager1->setMPHandle(pManager2);
    pManager2->setMPHandle(pCeo3);
    cout <<pManager1->handleFeeRequest(128)<< endl;
    cout <<pManager1->handleFeeRequest(512)<< endl;
    cout <<pManager1->handleFeeRequest(1024)<< endl;
    return 0;
}


/*
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
template<class T>
string MyConvertToString(T value) {
    stringstream ss;
    ss << value;
    return ss.str();
}

class FeeRequest {
public:
    string requestToPrjManager(double fee) {
        string strTrmp = "";
        if (fee < 500) {
            strTrmp = PrjHandle(fee);
        } else if (fee < 1000) { strTrmp = DepHandle(fee); }
        else if (fee >= 1000) {
            strTrmp = CE0(fee);
        }
        return strTrmp;
    }
private:
    string PrjHandle(double fee) {
        if (fee >= 0 && fee < 500) {
            return "PrjHandle agree " + MyConvertToString(fee) + " $";
        } else {
            return "PrjHandle is not agree " + MyConvertToString(fee) + " $";
        }
    }
    string DepHandle(double fee) {
        if (fee >= 500 && fee < 1000) {
            return "DepHandle agree " + MyConvertToString(fee) + " $";
        } else {
            return "DepHandle is not agree " + MyConvertToString(fee) + " $";
        }
    }
    string CE0(double fee) {
        if (fee >= 500 && fee < 1000) {
            return "CE0 agree " + MyConvertToString(fee) + " $";
        } else {
            return "CE0 is not agree " + MyConvertToString(fee) + " $";
        }
    }
protected:
};

int main() {
    auto pRequest = new FeeRequest;
    cout << pRequest->requestToPrjManager(1300) << endl;
    return 0;
}*/
