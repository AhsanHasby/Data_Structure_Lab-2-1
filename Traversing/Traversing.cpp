#include<iostream>
using namespace std;

int main(){
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    int array[n];
    cout << "Enter " << n << " integers: ";
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }
    int Max = array[0], Min = array[0], Total = array[0];
    for(int i = 1; i < n; i++) {
        if(array[i] > Max) Max = array[i];
        if(array[i] < Min) Min = array[i];
        Total += array[i];
    }

    cout << "Maximum value: " << Max << endl;
    cout << "Mininmum value: " << Min << endl;
    cout << "Average of the array: " << (float)Total/n << endl;
    cout << "Total value:" << Total << endl;


    return 0;
}