#include<bits/stdc++.h>
using namespace std;

bool isOperand(char ch) {
    if((ch >= '0' && ch <='9') || (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        return true;
    }
    return false;
}
int prec(char ch) {
    if(ch == '+' || ch == '-') return 1;
    if(ch == '*' || ch == '/') return 2;
    else if(ch == '^') return 3;
    else return -1;
}

string postfixExp(string s){
    string ans;
    stack<char> st;

    for(char ch : s) {
        if(isOperand(ch)) {
            ans += ch;
        }
        else if(ch == '(') {
            st.push(ch);
        }
        else if(ch == ')') {
            while(!st.empty() && st.top() != '(') {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        // Then must be -> Operator :
        else {  
            while(!st.empty() && (prec(st.top()) > prec(ch) || (prec(st.top()) == prec(ch) && ch != '^'))) {
                ans += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }

    while(!st.empty()) {
        ans += st.top();
        st.pop();
    }
    return ans;
}

int main() {
    string exp; 
    cout << "Infix Expression: ";
    cin >> exp;

    cout << "Postfix : " << postfixExp(exp);
    cout << endl;

    return 0;
}