#include <iostream>
#include <memory>
#include <list>
using namespace std;
class YouTubeChannel {
private:
    string _Name;
    string _OwnerName;
    int _SubscribersCount;
    list<string> _PublishedVideoTitles;
public:
    YouTubeChannel(string ownerName,
                   string name) {
        _Name = name;
        _OwnerName = ownerName;
        _SubscribersCount = 0;
    }

    void GetInfo(){
        cout<<"Name: "<<_Name<<endl;
        cout<<"OwnerName: "<<_OwnerName<<endl;
        cout<<"SubscribersCount: "<<_SubscribersCount<<endl;
        cout<<"Videos: "<<_Name<<endl;
        for (string videoTitle:_PublishedVideoTitles) {
            cout<<videoTitle<<endl;
        }
    }
    void Subscribe(){
        _SubscribersCount++;
    }
    void Unsubscribe(){
        if (_SubscribersCount>0)
        _SubscribersCount--;
    }
    void  PublishVideo(string title){
        _PublishedVideoTitles.push_back(title);
    }

};
int main() {
    YouTubeChannel ytChannel("CodeBeauty","Saldina");
    ytChannel.PublishVideo("C++ for beginners");
    ytChannel.PublishVideo("C++ OOP");
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Subscribe();
    ytChannel.Unsubscribe();
    ytChannel.Unsubscribe();
    ytChannel.Unsubscribe();
    ytChannel.GetInfo();

    return 0;
}
