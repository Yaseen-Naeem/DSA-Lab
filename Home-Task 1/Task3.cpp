#include <iostream>
using namespace std;

class DynamicArray {
private:
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray() {
        capacity = 2;
        size = 0;
        arr = new int[capacity];
    }

    void pushBack(int value) {

        if (size == capacity) {

            capacity = capacity * 2;

            int* newArr = new int[capacity];

            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }

            delete[] arr;

            // Pointing arr to newArr
            arr = newArr;
        }

        arr[size] = value;
        size++;
    }

    // [] operator
    int& operator[](int index) {

        if (index < 0 || index >= size) {
            cout << "Invalid index!" << endl;
            exit(1);
        }

        return arr[index];
    }

    DynamicArray(const DynamicArray& other) {

        size = other.size;
        capacity = other.capacity;

        arr = new int[capacity];

        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    // Copy assignment operator
    DynamicArray& operator=(const DynamicArray& other) {

        if (this != &other) {

            delete[] arr;

            size = other.size;
            capacity = other.capacity;

            arr = new int[capacity];

            for (int i = 0; i < size; i++) {
                arr[i] = other.arr[i];
            }
        }

        return *this;
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void print() const {

        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
    }
};

int main() {

    DynamicArray a;

    a.pushBack(10);
    a.pushBack(20);
    a.pushBack(30);
    a.pushBack(40);
    a.pushBack(50);
    a.pushBack(60);

    cout << "Original array:" << endl;
    a.print();

    DynamicArray b = a;

    // Modify copy
    b[0] = 100;

    cout << "\nAfter modifying copy:" << endl;

    cout << "Original array: ";
    a.print();

    cout << "Copied array: ";
    b.print();

    return 0;
}