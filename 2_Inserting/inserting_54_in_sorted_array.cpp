#include<iostream>
#include<cmath>
using namespace std;

int main(){
    int n; 
    cout << "Total elements in array: ";
    cin >> n;
    int arr[n+1]; // 10 20 30 40 50 60 70
    cout << "Enter the sorted array of size (" << n << "): ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    int value;
    cout << "Enter the element to insert: ";
    cin >> value;
    for(int i = n; i > 0; i--){
        arr[i] = arr[i-1];
        if(arr[i] <= value) {
            arr[i] = value;
            break;
        }
    }
    for(auto i : arr) cout << i << " ";
    return 0;
}