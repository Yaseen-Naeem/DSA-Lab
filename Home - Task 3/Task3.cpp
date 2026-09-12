// Synatax Fix: int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);

#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int interpolationSearch(int arr[], int n, int key, int &iterations) {
    int low = 0;
    int high = n - 1;
    iterations = 0;

    while (low <= high && key >= arr[low] && key <= arr[high]) {
        iterations++;

        if (arr[low] == arr[high]) {
            if (arr[low] == key) return low;
            return -1;
        }

        int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]));

        if (arr[pos] == key) {
            return pos;
        }

        if (arr[pos] < key) {
            low = pos + 1;
        } else {
            high = pos - 1;
        }
    }

    return -1; 
}

int main() {
    int iterations = 0;

    int uniformArr[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55, 60, 65, 70, 75, 80, 85, 90, 95, 100};
    int n1 = sizeof(uniformArr) / sizeof(uniformArr[0]);

    cout << "--- Task 11: Uniform Array Test ---" << endl;
    cout << "Array: ";
    printArray(uniformArr, n1);

    int idx1 = interpolationSearch(uniformArr, n1, 45, iterations);
    cout << "Search 45  -> Index: " << idx1 << " | Iterations: " << iterations << endl;


    int idx2 = interpolationSearch(uniformArr, n1, 37, iterations);
    cout << "Search 37  -> Index: " << idx2 << " | Iterations: " << iterations << endl;

    int nonUniformArr[] = {1, 2, 3, 4, 5, 1000};
    int n2 = sizeof(nonUniformArr) / sizeof(nonUniformArr[0]);

    cout << "\n--- Task 12: Non-Uniform Array Test ---" << endl;
    cout << "Array: ";
    printArray(nonUniformArr, n2);

    int idx3 = interpolationSearch(nonUniformArr, n2, 1000, iterations);
    cout << "Search 1000 -> Index: " << idx3 << " | Iterations: " << iterations << endl;

    return 0;
}