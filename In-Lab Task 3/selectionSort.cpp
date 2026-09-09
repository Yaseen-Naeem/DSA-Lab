#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        // Finding the index of the minimum element in the remaining unsorted part
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        
        // Swap the found minimum element with the first unsorted element
            swap(arr[i], arr[min]);
            count++;
    }
    cout << "Swapping Count: " << count << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    selectionSort(arr, n);

    cout << "Sorted array:   ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}