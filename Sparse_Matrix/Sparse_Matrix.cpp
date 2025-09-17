#include<iostream>
using namespace std;

int main() {
    int row = 3, column = 3;
    int TwoDimension[row][column] = {
        {1, 0, 0}, 
        {4, 5, 0}, 
        {7, 8, 9}};
    int OneDimension[row*column];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j <= min(i, j); j++) {
            OneDimension[(i*column) + j] = TwoDimension[i][j];
        }
    }

    for(auto i : OneDimension) cout << i << " ";
    cout << endl;

    return 0;
}