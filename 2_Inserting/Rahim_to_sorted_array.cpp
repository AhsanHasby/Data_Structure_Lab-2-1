#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
    int n;
    cout << "Enter the total of Students: ";
    cin >> n;
    string name[n+1];
    cout << "Enter the names: ";
    for(int i = 0; i < n; i++){
        cin >> name[i];
    }
    sort(name, name + n);
    string target;
    cout << "Enter target name: ";
    cin >> target;
    for(int i = n; i > 0; i++){
        name[i] = name[i-1];
        if(name[i] <= target) {
            name[i] = target;
            break;
        }
    }
    for(auto i : name) cout << i << " ";

    return 0;
}