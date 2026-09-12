#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void shellSort(int arr[], int n) {
    for (int gap = n / 2; gap > 0; gap /= 2) {
        
        for (int j = gap; j < n; j++) {
            int key = arr[j];
            int pos = j;

            while (pos >= gap && arr[pos - gap] > key) {
                arr[pos] = arr[pos - gap];
                pos -= gap;
            }

            arr[pos] = key; 
        }

        // Print array state after every gap pass
        cout << "Array after gap = " << gap << ": ";
        printArray(arr, n);
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    shellSort(arr, n);

    cout << "Final sorted array: ";
    printArray(arr, n);

    return 0;
}

/* Shell Sort outperforms plain Insertion Sort because shifting elements across large gap distances 
allows out-of-order elements to move quickly toward their final positions in few steps. */