#include<iostream>
using namespace std;

void MatrixAddition(int r, int c, int m1[][3], int m2[][3]) {
    int result[r][3];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }

    cout << "After Addition, The Matrix is: " << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void MatrixSubstraction(int r, int c, int m1[][3], int m2[][3]) {
    int result[r][3];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }

    cout << "After Substraction, The Matrix is: " << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

void MatrixMulitplication(int r, int c, int m1[][3], int m2[][3]) {
    int result[r][3];

    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            result[i][j] = 0;
            
            for(int k = 0; k < r; k++) {
                result[i][j] += m1[j][k]*m2[k][j];
            }
        }
    }

    cout << "After Multiplication, The Matrix is: " << endl;
    for(int i = 0; i < r; i++) {
        for(int j = 0; j < c; j++) {
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int row = 3, column = 3;
    int Mat1[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int Mat2[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    MatrixAddition(row, column, Mat1, Mat2);
    MatrixSubstraction(row, column, Mat1, Mat2);
    MatrixMulitplication(row, column, Mat1, Mat2);

    return 0;
}