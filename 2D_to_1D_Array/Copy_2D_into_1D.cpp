#include<iostream>
using namespace std;

int main() {
    int row = 3, column = 3;
    int TwoDimension[row][column] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int OneDimension[row*column];

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < column; j++) {
            OneDimension[(i*column) + j] = TwoDimension[i][j];
        }
    }

    int group = 3;
    
    cout << "Group " << group << " elements: " << endl;
    for(int i = group-1; i < row*column; i += group) {
        cout << OneDimension[i] << " ";
    }
    cout << endl;

    cout << "Full 1D Array: " << endl;
    for(auto i : OneDimension) cout << i << " ";

    return 0;
}