#include<iostream>
using namespace std;


template <typename T>
class ListNode{   //classs definition of Node 
  public:
    T data;
    ListNode<T> *next = nullptr;
};

//PASTE YOUR LINKED LIST CODE HERE
template <typename T>
class LinkedList {
  public: 
    ListNode<T> *start = nullptr;
    ListNode<T> *last = nullptr;
    ListNode<T> *loc = nullptr;
    ListNode<T> *ploc = nullptr;

// For my ease of use and ease of debugging
    void printList() {
        cout << "Wishlist: ";
        loc = start;
        while( loc!=nullptr ) {
            cout << loc->data << " ";
            loc = loc->next;
        }
        cout << endl;
    }

    void insertNode(T data) {
        ListNode<T> *newNode = new ListNode<T>;
        newNode->data = data;
        newNode->next = nullptr;
        if(start==nullptr) {
          start = newNode;
          last = newNode;
          return;
        }
        last->next = newNode;
        last = newNode;

        cout << data << " Successfully Added to WishList!" << endl;
    }

};

