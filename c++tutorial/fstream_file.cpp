#include <iostream>
#include <memory>
#include <fstream>
using namespace std;
int main() {
    fstream  myFile;
    myFile.open("saldina.txt",ios::out);
    if (myFile.is_open()){
        myFile<<"Hello\n";
        myFile<<"This is second line\n";
        myFile.close();
    }

    myFile.open("saldina.txt",ios::app);
    if (myFile.is_open()){
        myFile<<"Hello2\n";
        myFile<<"This is second line2\n";
        myFile.close();
    }

    myFile.open("saldina.txt",ios::in);
    if (myFile.is_open()) {
        string line;
        while (getline(myFile,line)){
            cout<<line<<endl;
        }
        myFile.close();
    }
        return 0;
}
