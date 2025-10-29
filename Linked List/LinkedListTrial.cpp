#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class List {
    Node* head;
    Node* tail;
public:    
    List() {
        head = nullptr;
        tail = nullptr;
    }
    
    void push_front(int value) {
        Node* new_node = new Node(value);
        if(head == nullptr) {
            head = tail = new_node;
        }
        else {
            new_node->next = head;
            head = new_node;
        }

    }
    void push_back(int value) {
        Node* new_node = new Node(value);
        if(head == nullptr) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    
    void traverse() {
        if(head == nullptr) {
            cout << "LINKED LIST IS EMPTY" << endl;
            return;
        }
        cout << "Linked List:\n";
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    
    void pop_front() {
        if(head == nullptr) {
            cout << "LINKED LIST IS EMPTY!";
            return;
        }
        Node* temp = head;
        head = temp->next;
        delete temp;
        if(head == nullptr) {
            tail = nullptr;
        }
    }
    void pop_back() {
        if(head == nullptr) {
            cout << "LINKED LIST IS EMPTY!";
            return;
        }
        Node* temp = head;
        while(temp->next != tail) {
            temp = temp->next;
        }
        temp->next = nullptr;
        delete tail;
        tail = temp;

    }

};


int main() {
    List ll;
    
    int n = 5;
    for(int i = 0; i < n; i++) {
        ll.push_back(i+1);
    }
    ll.traverse();
    
    ll.pop_front();
    ll.pop_front();
    ll.traverse();

    ll.pop_back();
    ll.pop_back();
    ll.traverse();

    cout << "Main ended" << endl;
    return 0;
}