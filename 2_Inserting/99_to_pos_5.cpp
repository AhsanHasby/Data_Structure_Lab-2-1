#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n; 
    cout << "Total elements in array: ";
    cin >> n;
    int arr[n+1]; // 10 20 30 40 50 60 70 80 90
    cout << "Enter the array of size (" << n << "): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int value, pos;
    cout << "Enter the element to insert: ";
    cin >> value;
    cout << "Enter the position: ";
    cin >> pos;
    for(int i = n; i > 0; i--){
        arr[i] = arr[i-1];
        if(i+1 == pos) {
            arr[i] = value;
            break;
        }
    }
    for(auto i : arr) cout << i << " ";
    return 0;
}