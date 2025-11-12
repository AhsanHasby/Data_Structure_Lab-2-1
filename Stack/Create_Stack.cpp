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

    void isEmpty() {
        if(last == -1) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        cout << "Stack is Non-Empty" << endl;
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


};

int main() {
    Stack st;

    st.isEmpty();
    
    st.push(10);
    st.push(20);
    st.push(30);

    cout << st.top() << endl;
    
    st.pop();
    cout << st.top() << endl;

    return 0;
}