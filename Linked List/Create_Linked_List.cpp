#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }

};

class List {
    Node* head;
    Node* tail;

public:
    List() {
        head = tail = NULL;
    }

    void push_front(int value) {
        Node* new_node = new Node(value);
        if(head == NULL) {
            head = tail = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }
    }

};


int main () {
    List ll;
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);

    return;
}