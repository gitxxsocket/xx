#include <iostream>
#include <memory>
#include <list>

using namespace std;


class YouTubeChannel {
public:
    string Name;
    string OwnerName;
    int SubscribersCount;
    list<string> PublishedVideoTitles;

    YouTubeChannel(string ownerName,
                   string name) {
        Name = name;
        OwnerName = ownerName;
        SubscribersCount = 0;
    }

    void GetInfo(){
        cout<<"Name: "<<Name<<endl;
        cout<<"OwnerName: "<<OwnerName<<endl;
        cout<<"SubscribersCount: "<<SubscribersCount<<endl;
        cout<<"Videos: "<<Name<<endl;
        for (string videoTitle:PublishedVideoTitles) {
            cout<<videoTitle<<endl;
        }
    }

};

int main() {
    YouTubeChannel ytChannel1("CodeBeauty","Saldina");
    ytChannel1.PublishedVideoTitles.push_back("C++ for beginners");
    ytChannel1.PublishedVideoTitles.push_back("C++ OOP");
    YouTubeChannel ytChannel12("CodeBeauty","Amy");
    ytChannel1.GetInfo();
    cout<<"-----------------: "<<endl;
    ytChannel12.GetInfo();

    return 0;
}
