#include<bits/stdc++.h>
using namespace std;

float calc(char ch, float a, float b) {
    if(ch == '+') return b+a;
    else if(ch == '-') return b-a;
    else if(ch == '*') return b*a;
    else if(ch == '/') return b/a;
    else if(ch == '^') return pow(b, a);
    else return 0;
} 


bool isOperand(char ch) {
    if(ch >= '0' && ch <= '9') {
        return true;
    }
    return false;
}

float postFixEval(string s) {
    stack<float> stk;
    
    for(int i = 0; i < s.length(); i++) {
        if(isOperand(s[i])) {
            stk.push((float)s[i]-'0');
        }
        else {
            int a = stk.top();
            stk.pop();
            int b = stk.top();
            stk.pop();

            stk.push(calc(s[i], a, b));
        }
    }
    return stk.top();
}

string check(string s) {
    for(int i = 0; i < s.length(); i++) {
        if((s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= 'a' && s[i] <= 'z')) {
            cout << "Value of " << s[i] << " : ";
            int x;
            cin >> x;
            s[i] = x + '0';
        } 
    }
    
    return s;
}

int main() {
    string test;
    cout << "Enter postfix expression : ";
    cin >> test;

    string post = check(test);

    float result = postFixEval(post);
    cout << "Result is = " << result << endl;

    return 0;
}