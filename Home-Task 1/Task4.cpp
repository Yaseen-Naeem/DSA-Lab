/*
The class has a dynamic array but no copy constructor or copy assignment operator.
So, when b2 = b1, both objects point to the same memory (shallow copy).
Changing b2 also changes b1, and when both objects are destroyed, the same memory
is deleted twice, which can cause a crash.
The problem is visible in display() because both objects will show the same data.
*/


#include <iostream>
using namespace std;

class Buffer {
private:
    int* data;
    int length;

public:
    Buffer(int len) {
        length = len;
        data = new int[length];

        for (int i = 0; i < length; i++) {
            data[i] = 0;
        }
    }

    Buffer(const Buffer& other) {
        length = other.length;
        data = new int[length];

        for (int i = 0; i < length; i++) {
            data[i] = other.data[i];
        }
    }

    // Copy assignment operator
    Buffer& operator=(const Buffer& other) {
        if (this != &other) {
            delete[] data;

            length = other.length;
            data = new int[length];

            for (int i = 0; i < length; i++) {
                data[i] = other.data[i];
            }
        }

        return *this;
    }

    void setValue(int index, int value) {
        data[index] = value;
    }

    void display() const {
        for (int i = 0; i < length; i++) {
            cout << data[i] << " ";
        }

        cout << endl;
    }

    ~Buffer() {
        delete[] data;
    }
};

int main() {

    Buffer b1(5);

    b1.setValue(0, 10);

    Buffer b2 = b1;

    b2.setValue(1, 20);

    b1.display();
    b2.display();

    return 0;
}