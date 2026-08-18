#include <iostream>
#include <cstring>
using namespace std;

class DynamicString {
private:
    char* data;

public:
    DynamicString(const char* text) {
        data = new char[strlen(text) + 1];
        strcpy(data, text);
    }

    DynamicString(const DynamicString& other) {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }

    DynamicString& operator=(const DynamicString& other) {
        if (this != &other) {
            delete[] data;

            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }

        return *this;
    }

    ~DynamicString() {
        delete[] data;
    }

    int length() const {
        return strlen(data);
    }

    void print() const {
        cout << data << endl;
    }

    void setChar(int index, char c) {
        data[index] = c;
    }
};

int main() {

    DynamicString s1("Hello");
    DynamicString s2 = s1;

    DynamicString s3("World");
    s3 = s1;

    cout << "Before modification:" << endl;

    cout << "s1: ";
    s1.print();

    cout << "s2: ";
    s2.print();

    cout << "s3: ";
    s3.print();

    s1.setChar(0, 'J');

    cout << "\nAfter modifying s1:" << endl;

    cout << "s1: ";
    s1.print();

    cout << "s2: ";
    s2.print();

    cout << "s3: ";
    s3.print();

    return 0;
}