#include <iostream>
using namespace std;

class Rectangle {
private:
    int* width;
    int* height;

public:
    // Constructor
    Rectangle(int w, int h) {
        width = new int(w);
        height = new int(h);
    }

    // Return width pointer
    int* getWidthPointer() const {
        return width;
    }

    // Change width value
    void setWidth(int w) {
        *width = w;
    }

    void display() const {
        cout << "Width: " << *width << endl; 
    }

    ~Rectangle() {
        delete width;
        delete height;

        cout << "Rectangle destroyed" << endl;
    }
};

int main() {

    Rectangle r1(4, 5);
    Rectangle r2 = r1;

    cout << "r1 width pointer: " << r1.getWidthPointer() << endl;
    cout << "r2 width pointer: " << r2.getWidthPointer() << endl;

    r2.setWidth(10);

    cout << "\nAfter changing r2 width:\n";
    r1.display();

    /*
       r1 and r2 have the same width pointer because the default copy constructor performs a shallow copy.
       When r1 and r2 are destroyed, both destructors will try to delete the same memory address.
       This causes a double deletion problem.
    */

    return 0;
}