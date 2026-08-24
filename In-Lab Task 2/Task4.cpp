#include <iostream>
using namespace std;

class SafeArray{
    public:
    int size;
    int* arr;

    SafeArray(int s){
        size = s;
        arr = new int[s];

        for(int i = 0; i < size; i++){
        arr[i] = 0;
        }
    }

    void set(int pos, int val){
        if(pos < 0 || pos >=size){
            cout << "Boundary Error!" << endl;
            return;
        }

        else{
            arr[pos] = val;
        }
    }

    int get(int pos){
         if(pos < 0 || pos >=size){
            cout << "Boundary Error!" << endl;
            return -1;
        }

        else{
            return arr[pos];
        }
    }

    void display(){
        for(int i =0; i< size; i++){
            cout << arr[i] << " ";
        }
    }

    ~SafeArray(){
        delete [] arr;
    }
};

int main(){
    SafeArray a(5);

    a.set(10, 6);
    cout << a.get(10) << endl;

    a.set(3, 7);
    cout << a.get(3) << endl;

    cout << "\nArray Display...." << endl;
    a.display();

    return 0;
}