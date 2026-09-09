#include <iostream>
using namespace std;

void combSort(int arr[], int n) {

    int count = 0;
    int gap = n;
    bool swapped = true;

    while (gap > 1 || swapped) {
        // Shrink gap by factor of 1.3
        gap = (gap * 10) / 13;
        if (gap < 1) gap = 1;

        swapped = false;

        // Compare elements with current gap
        for (int i = 0; i < n - gap; i++) {
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swapped = true;
                count++;
            }
        }
    }
    cout << "Swapping Count: " << count << endl;
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {8, 4, 1, 56, 3, -44, 23, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    combSort(arr, n);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}