//
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
template<class T>
struct MyList_node {
    MyList_node<T> *prev;
    MyList_node<T> *next;
    T data;
};

template<class T>
struct MyList_iterator {
    typedef MyList_iterator<T> iterator;
    typedef MyList_node<T> *link_type;
    link_type node;
    MyList_iterator(link_type x) : node{x} {
    }
    MyList_iterator() : node(nullptr) {
    }
    iterator &operator++() {
        node = node->next;
        //返回本对象 同时指向下一个
        return *this;
    }
    iterator &operator++(int) {
        iterator tmp = *this;
        ++*this;
        return tmp;
    }

    iterator &operator()(){node = (node)->prev;return *this;}
};

int main() {
    MyList_node<int> x;
    return 0;
}