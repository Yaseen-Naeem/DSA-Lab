#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int target) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == target) {
            return mid; 
        }

        // If target is greater, ignore left half
        if (arr[mid] < target) {
            low = mid + 1;
        } 
        // If target is smaller, ignore right half
        else {
            high = mid - 1;
        }
    }

    return -1;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {

    int arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;

    cout << "Sorted array: ";
    printArray(arr, n);

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        cout << "Element " << target << " found at index: " << result << endl;
    } else {
        cout << "Element " << target << " not found in array" << endl;
    }

    return 0;
}