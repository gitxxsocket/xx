// 撤销数据
// 备忘录模式
// 持久化数据  网络  数据库
//ODBC 数据库
//Http Session
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class OriginalWord;

class Memento {
private:
    friend class OriginalWord;

    string m_strWord;
    const string &getMStrWord() const {
        return m_strWord;
    }
public:
    Memento(const string &mStrWord) : m_strWord(mStrWord) {
    }
};

class OriginalWord {
    string m_strWord;
public:
    OriginalWord(const string &mStrWord) : m_strWord(mStrWord) {}
    Memento *saveWorlds() {
        cout <<  "  saveWorlds  "<< endl;

        return new Memento(m_strWord);

    }
    void recycleWords(Memento *m_pMemento) {
        m_strWord = m_pMemento->getMStrWord();
        cout <<  " seuccess  recycleWords  "<< endl;

    }
    void showords( ) {
        cout <<  m_strWord<< endl;
    }
};

/*class OriginalWord {
public:
    void setMStrWord(const string &mStrWord) {
        m_strWord = mStrWord;
    }
    void resetMStrWord(const string &mStrWord) {
        m_strWord = mStrWord;
    }
protected:
    string m_strWord;
};*/
class Caretake {
        public:
    void setMPMemento(Memento *mPMemento) {
        m_pMemento = mPMemento;
    }
    Memento *getMPMemento() const {
        return m_pMemento;
    }
protected:
private:
    Memento *m_pMemento;
};

int main() {
    auto pWordFst = new OriginalWord("c++");
    cout << "-------------------" << endl;
    cout << "pWordFst" << endl;
    pWordFst->showords();

    auto pCaretake = new Caretake;
    cout << "-------------------" << endl;
    cout << "saveWorlds" << endl;
    pCaretake->setMPMemento(pWordFst->saveWorlds());

    auto pWordSec = new OriginalWord("c++++++");
    cout << "-------------------" << endl;
    cout << "pWordSec" << endl;
    pWordSec->showords();

    auto pWordThd = new OriginalWord("+++++c");
    cout << "-------------------" << endl;
    cout << "recycleWords" << endl;
    pWordFst->recycleWords(pCaretake->getMPMemento());
    pWordFst->showords();


    return 0;
}