#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Data {
public:
    Data() { cout << "(Data)" << endl; }
    virtual ~Data() {
        cout << "~(Data)" << endl;
    }
    int index = 0;
protected:
};

vector<Data *> TestVec(vector<Data> &data) {
    cout << "TestVec data = "<<data.data() << endl;
    vector<Data *> re;
    re.resize(30);
    cout << "re data = "<<re.data() << endl;
    cout << "re.size()*sizeof (Data) = "<<re.size()*sizeof (Data)<< endl;

    return re;
}
int main() {
    {
        vector<Data> vd;
        Data d;
        d.index = 1;
        vd.push_back(d);
        d.index = 2;
        vd.push_back(d);
        d.index = 3;
        vd.push_back(d);
        TestVec(vd);
        cout << "" << vd.data() << endl;

    }
    return 0;
}