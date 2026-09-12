#include <iostream>
#include <cstdlib>
#include <chrono>

using namespace std;
using namespace std::chrono;

void copyArray(int src[], int dest[], int n) {
    for (int i = 0; i < n; i++) dest[i] = src[i];
}

void bubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) swap(a[j], a[j + 1]);
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minI = i;
        for (int j = i + 1; j < n; j++) 
            if (a[j] < a[minI]) minI = j;
        swap(a[i], a[minI]);
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i], j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }
}

void shellSort(int a[], int n) {
    for (int g = n / 2; g > 0; g /= 2)
        for (int i = g; i < n; i++) {
            int temp = a[i], j = i;
            while (j >= g && a[j - g] > temp) {
                a[j] = a[j - g];
                j -= g;
            }
            a[j] = temp;
        }
}

void combSort(int a[], int n) {
    int g = n;
    bool swapped = true;
    while (g > 1 || swapped) {
        g = (g * 10) / 13;
        if (g < 1) g = 1;
        swapped = false;
        for (int i = 0; i < n - g; i++) {
            if (a[i] > a[i + g]) {
                swap(a[i], a[i + g]);
                swapped = true;
            }
        }
    }
}

int main() {
    int sizes[] = {100, 1000, 10000, 50000};

    cout << "n\tBubble\tSelect\tInsert\tShell\tComb\n";

    for (int n : sizes) {
        int* orig = new int[n];
        int* arr = new int[n];

        for (int i = 0; i < n; i++) orig[i] = rand();

        cout << n << "\t";

        // Bubble
        copyArray(orig, arr, n);
        auto t1 = high_resolution_clock::now();
        bubbleSort(arr, n);
        auto t2 = high_resolution_clock::now();
        cout << duration<double, milli>(t2 - t1).count() << "ms\t";

        // Selection
        copyArray(orig, arr, n);
        t1 = high_resolution_clock::now();
        selectionSort(arr, n);
        t2 = high_resolution_clock::now();
        cout << duration<double, milli>(t2 - t1).count() << "ms\t";

        // Insertion
        copyArray(orig, arr, n);
        t1 = high_resolution_clock::now();
        insertionSort(arr, n);
        t2 = high_resolution_clock::now();
        cout << duration<double, milli>(t2 - t1).count() << "ms\t";

        // Shell
        copyArray(orig, arr, n);
        t1 = high_resolution_clock::now();
        shellSort(arr, n);
        t2 = high_resolution_clock::now();
        cout << duration<double, milli>(t2 - t1).count() << "ms\t";

        // Comb
        copyArray(orig, arr, n);
        t1 = high_resolution_clock::now();
        combSort(arr, n);
        t2 = high_resolution_clock::now();
        cout << duration<double, milli>(t2 - t1).count() << "ms\n";

        delete[] orig;
        delete[] arr;
    }

    return 0;
}