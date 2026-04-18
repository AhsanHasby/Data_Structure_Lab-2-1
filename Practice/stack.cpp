#include<bits/stdc++.h>
using namespace std;
#define MAX 100
char arr[MAX];
int idx = -1;

struct Stack {

    void push(int x) {
        if(idx == MAX-1) {
            cout << "Stack Overflow";
            return;
        }
        arr[++idx] = x;
    }
    void pop() {
        if(idx == -1) {
            cout << "Stack Underflow";
            return;
        }
        idx--;
    }
    char top() {
        if(idx == -1) {
            cout << "Stack empty";
            return 1;
        }
        return arr[idx];
    }
    void show() {
        if(idx == -1) {
            cout << "Stack empty";
            return;
        }
        cout << "Stack elements : ";
        for(int i = 0; i < idx; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    cout << "Stack size = ";
    int size;
    cin >> size;
    Stack stk;

    while(true) {
        cout << "1: insert\n2:delete\n3:top element\n4:print stack\n";
        int cmd;
        cin >> cmd;
        switch(cmd) {
            case 1:
                char ch;
                cin >> ch;
                stk.push(ch);
                break;
            case 2:
                stk.pop();
                break;
            case 3:
                cout << stk.top() << endl;
                break;
            case 4:
                stk.show();
                break;
            default:
                cout << "Invalid choice\n";
                return 0;

        }
    }

    return 0;
}