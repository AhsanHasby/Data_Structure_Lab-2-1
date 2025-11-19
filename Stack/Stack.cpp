#include<iostream>
using namespace std;

class Stack {
private:
    int arr_size;
    int* arr;
    int last;
    int size = 0;

public:
    Stack() {
        arr_size = 1000;
        arr = new int[arr_size];
        last = -1;
    }
    Stack(int n) {
        arr_size = n;
        arr = new int[n];
        last = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    int isEmpty() {
        if(last == -1) {
            return 1;
        }
        return 0;
    }
    int capacity() {
        return size;
    }

    void push(int x) {
        if(last == arr_size - 1) {
            cout << "Stack Overflow" << endl;
            return;
        }
        ++size;
        arr[++last] = x;
    }

    void pop() {
        if(last == -1) {
            cout << "Stack is Empty!"  << endl;
            return;
        }
        --size;
        --last;
    }

    int top() {
        if(last == -1) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        return arr[last];
    }

    void print() {
    if (last == -1) {
        cout << "";
        return;
    }
    for (int i = 0; i <= last; i++) {
        cout << arr[i] << " ";
    }
}


};