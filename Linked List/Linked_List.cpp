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
    //Insertion
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
    void push_back(int value) {
        Node* new_node = new Node(value);
        if(head == NULL) {
            head = tail = NULL;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    //Traversing
    void printLL() {
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next; 
        }
        cout << endl;
    }
    //Deletion
    void pop_front() {
        if(head == NULL) {
            cout << "LINKED LIST IS EMPTY!" << endl;
            return;
        }
        Node* temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    }
    void pop_back() {
        if(head == NULL) {
            cout << "LINKED LIST IS EMPTY!" << endl;
            return;
        }
        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        delete tail;
        tail = temp;
    }

};


int main () {
    List ll;
    // Insertion
    ll.push_front(1);
    ll.push_front(2);
    ll.push_front(3);
    ll.printLL();

    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.printLL();
    // Deletion
    ll.pop_front();
    ll.pop_front();
    ll.printLL();

    ll.pop_back();
    ll.pop_back();
    ll.printLL();

    return 0;
}