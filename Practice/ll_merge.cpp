#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* link;
    Node(int val) {
        data = val;
        link = nullptr;
    }
};

void display(Node* head) {
    cout << "Linked List elements : \n";
    if(head == nullptr) {
        cout << "Empty list" ;
        return;
    }
    
    Node* temp = head;
    while(temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->link;
    }
    cout << endl;
}

Node* llSort(Node* head) {
    cout << "Sorted ";
    Node* ptr1 = head;
    while(ptr1 != nullptr) {
        Node* ptr2 = ptr1->link;
        while(ptr2 != nullptr) {
            if(ptr2->data < ptr1->data) {
                int temp = ptr2->data;
                ptr2->data = ptr1->data;
                ptr1->data = temp;
            }
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
    return head;
}

Node* llMerge(Node* head1, Node* head2) {
    if(head1 == nullptr) return head2;
    
    Node* temp = head1;
    while(temp->link != nullptr) {
        temp = temp->link;
    }
    temp->link = head2;
    return head1;
}

Node* llIntersect(Node* head1, Node* head2) {
    if(head1 == nullptr || head2 == nullptr) return nullptr;

    Node* head = nullptr;
    Node* tail = head;

    Node* ptr1 = head1;
    while(ptr1 != nullptr) {
        Node* ptr2 = head2;
        while(ptr2 != nullptr) {
            if(ptr1->data == ptr2->data) {
                if(head == nullptr) {
                    head = new Node(ptr1->data);
                    tail = head;
                }
                else {
                    Node* newNode = new Node(ptr1->data);
                    tail->link = newNode;
                    tail = newNode;
                }
                break;
            }
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
    return head;
}

void llSplit(Node* head) {
    if(head == nullptr || head->link == nullptr) {
        cout << "Can't be split\n";
        return;
    }
    Node* fast = head;
    Node* slow = head;
    while(fast->link != nullptr && fast->link->link != nullptr) {
        slow = slow->link; //Points to middle
        fast = fast->link->link;
    }
    Node* front = head;
    Node* back = slow->link; //One step ahead of middle
    slow->link = nullptr;

    cout << "Front ";
    display(front);
    cout << "Back ";
    display(back);
}

int main() {
    cout << "Enter size of first Linked list : ";
    int first; 
    cin >> first;
    cout << "Enter first Linked list elements: ";
    int x;
    cin >> x;
    Node* head1 = new Node(x);
    Node* ptr1 = head1;
    for(int i = 0; i < first - 1; i++) {
        cin >> x;
        Node* newNode = new Node(x);
        ptr1->link = newNode;
        ptr1 = newNode;
    }
    display(head1);

    cout << "Enter size of the second Linked list : ";
    int second; 
    cin >> second;
    cout << "Enter the second LL elements : ";
    int y;
    cin >> y;
    Node* head2 = new Node(y);
    Node* ptr2 = head2;
    for(int i = 0; i < second - 1; i++) {
        cin >> y;
        Node* newNode = new Node(y);
        ptr2->link = newNode;
        ptr2 = newNode;
    }
    display(head2);


    Node* head;
    while(true) {
        cout << "Press 1: Merge, \nPress 2: Intersection\nPress 3: Sort\nPress 4: Split\n";
        int option;
        cin >> option;
        switch(option){
        case 1: 
            head = llMerge(head1, head2);
            cout << "Merged List : ";
            display(head);
            break;
        case 2:
            head = llIntersect(head1, head2);
            cout << "Intersection List : ";
            display(head);
            break;
        case 3:
            llSort(head1);
            display(head1);
            llSort(head2);
            display(head2);
            break;
        case 4: 
            llSplit(head1);
            llSplit(head2);
            break;
        default:
            cout << "Invalid choice";
            return 0;
        }
    }
    
    return 0;
}