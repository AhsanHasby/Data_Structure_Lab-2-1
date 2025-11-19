#include<iostream>
#include<cmath>
#include "Stack.cpp"

using namespace std;

int main() {
    int size = 0; 
    cout << "Enter the number of elements: " << endl;
    cin >> size;

    Stack st;
    cout << "Scanned symbol\t" << "Stack" << endl;
    for(int i = 0; i < size; ++i) {
        string element; cin >> element;
        
        
        cout << element << "\t\t";
        st.print();
        cout << endl;

        if(element == "+" || element == "-" || element == "*" || element == "/" || element == "^") {
            float x = st.top();
            st.pop();
            float y = st.top();
            st.pop();
            if(element == "+") st.push(y + x);
            if(element == "-") st.push(y - x);
            if(element == "*") st.push(y * x);
            if(element == "/") st.push(y / x);
            if(element == "^") st.push(pow(y, x));

        }
        else {
            int value = stoi(element);
            st.push(value);
        }
    }

    double result = st.top();

    cout << "Final Result is " << result << endl;

    return 0;
}