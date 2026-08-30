#include <iostream>
using namespace std;

class DynamicSafeArray{
    public:
    int* arr;
    int capacity;
    int count;


    DynamicSafeArray(int initialCapacity){
        capacity = initialCapacity;
        count = 0;

        arr = new int[capacity];
    }

    void pushBack(int val){
        if(count == capacity){
            int newCapacity = capacity * 2;

            int* newArr = new int[newCapacity];

            for(int i = 0; i < count; i++){
                newArr[i] = arr[i];
            }

            delete[] arr;

            arr = newArr;
            capacity = newCapacity;
        }
        arr[count] = val;
        count++;
    }

    void set(int pos, int val){
        if(pos < 0 || pos >= count){
            cout << "Boundary Error!" << endl;
            return;
        }
        arr[pos] = val;
    }


    int get(int pos){
        if(pos < 0 || pos >= count){
            cout << "Boundary Error!" << endl;
            return -1;
        }
        return arr[pos];
    }


    bool removeAt(int pos){
        if(pos < 0 || pos >= count){
            cout << "Boundary Error!" << endl;
            return false;
        }

        for(int i = pos; i < count - 1; i++){
            arr[i] = arr[i + 1];
        }

        count--;
        return true;
    }


    void display(){
        for(int i = 0; i < count; i++){
            cout << arr[i] << " ";
        }

        cout << endl;
    }


    ~DynamicSafeArray(){
        delete[] arr;
    }
};


int main(){
    DynamicSafeArray a(2);

    a.pushBack(10);
    a.pushBack(20);
    a.pushBack(30);
    a.pushBack(40);
    a.pushBack(50);
    a.pushBack(60);

    cout << "Array after pushBack:" << endl;
    a.display();

    // Removing middle element
    a.removeAt(2);

    cout << "After removing position 2:" << endl;
    a.display();

    cout << "Element at position 1: "
         << a.get(1) << endl;

    cout << "Trying to get position 10:" << endl;
    a.get(10);

    cout << "Trying to set position 10:" << endl;
    a.set(10, 100);


    return 0;
}