#include <iostream>
using namespace std;

// Structure to create a node with data and the next pointer
struct node {
    public:
        string data;
        node * next;
};

class Queue {

    public:
    node *front = nullptr;
    node *rear = nullptr;

    // Enqueue() operation on a queue
    void enqueue(string value) {
        node *ptr = new node();
        ptr -> data = value;
        ptr -> next = NULL;
        if ((front == NULL) && (rear == NULL)) {
            front = ptr;
            rear = ptr;
        } else {
            rear -> next = ptr;
            rear = ptr;
        }
        cout << value << " Added to Downloads!" << endl;
    }

    // Dequeue() operation on a queue
    string dequeue() {
        if (front == NULL) {
            cout << "Queue underflow error!";
            return "";
        } else {
            struct node * temp = front;
            string temp_data = front -> data;
            front = front -> next;
            free(temp);
            return temp_data;
        }
    }

};

