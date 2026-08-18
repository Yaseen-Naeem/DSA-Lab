#include <iostream>
using namespace std;

class Rectangle {
private:
    int* width;
    int* height;

public:
    Rectangle(int w, int h) {
        width = new int(w);
        height = new int(h);
    }

    // Deep Copy Constructor
    Rectangle(const Rectangle& other) {
        width = new int(*other.width);
        height = new int(*other.height);
    }

    int* getWidthPointer() const {
        return width;
    }

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

    cout << "\nr1:" << endl;
    r1.display();

    cout << "\nr2:" << endl;
    r2.display();

    return 0;
}