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
        head = tail = nullptr;
    }
    //Insertion
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
            head = tail = nullptr;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
    }
    void insert_at(int value, int pos) {
        if(pos == 0) {
            push_front(value);
            return;
        }

        Node* temp = head;
        int current_pos = 0;
        while(temp != nullptr && current_pos < pos - 1) {
            temp = temp->next;
            current_pos++;
        }
        if(temp == nullptr) {
            cout << "Array Index Out Of Bound!\n";
            return;
        }

        Node* new_node = new Node(value);
        new_node->next = temp->next;
        temp->next = new_node;
        if(new_node->next == nullptr) {
            tail = new_node;
        }
    }

    //Traversing
    void printLL() {
        Node* temp = head;
        while(temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next; 
        }
        cout << endl;
    }
    //Deletion
    void pop_front() {
        if(head == nullptr) {
            cout << "LINKED LIST IS EMPTY!" << endl;
            return;
        }
        Node* temp = head;
        head = temp->next;
        temp->next = nullptr;
        delete temp;
    }
    void pop_back() {
        if(head == nullptr) {
            cout << "LINKED LIST IS EMPTY!" << endl;
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

    ll.insert_at(10, 4);
    ll.printLL();

    // Deletion
    // ll.pop_front();
    // ll.pop_front();
    // ll.printLL();

    // ll.pop_back();
    // ll.pop_back();
    // ll.printLL();

    return 0;
}