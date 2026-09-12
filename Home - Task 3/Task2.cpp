#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void combSort(int arr[], int n) {
    int gap = n;
    bool swapped = true;
    int comparisons = 0;
    int swaps = 0;

    while (gap > 1 || swapped) {
        gap = (int)(gap / 1.3);
        if (gap < 1) gap = 1;

        swapped = false;

        for (int i = 0; i < n - gap; i++) {
            comparisons++;
            if (arr[i] > arr[i + gap]) {
                swap(arr[i], arr[i + gap]);
                swaps++;
                swapped = true;
            }
        }
    }

    cout << "\n Comb Sort Results: " << endl;
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Swaps:       " << swaps << endl;
}

void bubbleSort(int arr[], int n) {
    int comparisons = 0;
    int swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swaps++;
            }
        }
    }

    cout << "\n Bubble Sort Results: " << endl;
    cout << "Total Comparisons: " << comparisons << endl;
    cout << "Total Swaps:       " << swaps << endl;
}

int main() {
    int original[] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(original) / sizeof(original[0]);

    int combArr[20], bubbleArr[20];
    for (int i = 0; i < n; i++) {
        combArr[i] = original[i];
        bubbleArr[i] = original[i];
    }

    cout << "Original Array: ";
    printArray(original, n);

    combSort(combArr, n);
    cout << "Comb Sort Array: ";
    printArray(combArr, n);

    bubbleSort(bubbleArr, n);
    cout << "Bubble Sort Array: ";
    printArray(bubbleArr, n);

    return 0;
}
