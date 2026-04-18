#include<bits/stdc++.h>
using namespace std;
#define MAX 100

struct Queue {
    char arr[MAX];
    int front = -1;
    int rear = -1;

    void push(char x){
        if(rear == MAX - 1) {
            cout << "Overflow";
            return;
        }
        if(front == -1) front++;
        arr[++rear] = x;
    }
    void pop(){
        if(front == -1 || front > rear) {
            cout << "Underflow";
            return;
        }
        front++;
    }
    char top(){
        if(front == -1) {
            cout << "Empty queue !";
            return '\0';
        }
        return arr[front];
    }
    void display(){
        if(front == -1) {
            cout << "Empty queue!";
            return;
        }
        cout << "Queue elements: ";
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

};

int main() {
    Queue que;

    while(true) {
        int cmd;
        cout << "1: insert\n2:remove\n3:front element\n4:Display Queue\n Choice: ";
        cin >> cmd;
        switch(cmd) {
            case 1:
                cout << "Enter element: ";
                char x; cin >> x;
                que.push(x);
                break;
            case 2:
                que.pop();
                break;
            case 3:
                cout << "Front element : ";
                cout << que.top() << endl;
                break;
            case 4:
                cout << "Queue elements: ";
                que.display();
                break;
            default:
                cout << "Invalid choice\n";
                return 0;

        }
    }

    return 0;
}