#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream file("int_sorted.txt");
    if (!file) {
        cout << "Error opening the file" << endl;
        return -1;
    }
    int n;
    file >> n;
    int arr[n]; // Variable Length Array (VLA) — allowed by some compilers like GCC, but not standard C++
    for(int i = 0; i < n; i++) {
        file >> arr[i];
    }
    int target;
    cout << "Enter the element to search: ";
    cin >> target;
    int beg = 0, end = n - 1, indx = -1;
    while(beg <= end) {
        int mid = (beg + end) / 2;
        if (target < arr[mid]) {
            end = mid - 1;
        } else if (target > arr[mid]) {
            beg = mid + 1;
        } else {
            indx = mid;
            break;
        }
    }
    if(indx == -1) {
        cout << "Element not found in the array." << endl;
    }
    else {
        cout << "Element is at position " << indx + 1 << " in the array." << endl;
    }

    return 0;
}
