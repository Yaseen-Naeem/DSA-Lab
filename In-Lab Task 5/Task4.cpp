#include <iostream>
#include <string>
using namespace std;

class CircularQueue{
    public:
    string arr[100];
    int N;
    int front;
    int rear;

    CircularQueue(int n){
        N = n;
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (rear + 1) % N == front;
    }

    void enqueue(string name){
        if(isFull()){
            cout << "Queue is full, cannot add " << name << endl;
            return;
        }

        if(isEmpty()){
            front = 0;
            rear = 0;
        }
        else{
            rear = (rear + 1) % N;
        }
        arr[rear] = name;
        cout << name << " added to queue" << endl;
    }

    void dequeue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Serving " << arr[front] << endl;
        if(front == rear){
            front = -1;
            rear = -1;
        }
        else{
            front = (front + 1) % N;
        }
    }

    void displayQueue(){
        if(isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        int i = front;
        while(true){
            cout << arr[i];

            if(i == rear)
                break;
            cout << ", ";
            i = (i + 1) % N;
        }

        cout << endl;
    }
};

int main(){
    int N;

    cout << "Enter maximum number of customers: ";
    cin >> N;
    CircularQueue queue(N);

    int choice;
    string name;


    do{
        cout << endl;
        cout << "1. Add Customer" << endl;
        cout << "2. Serve Customer" << endl;
        cout << "3. View Queue" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;

        if(choice == 1){
            cout << "Enter customer name: ";
            cin >> name;

            queue.enqueue(name);
        }
        else if(choice == 2){
            queue.dequeue();
        }

        else if(choice == 3){
            queue.displayQueue();
        }
        else if(choice == 4){
            cout << "Exiting..." << endl;
        }
        else{
            cout << "Invalid choice" << endl;
        }

    } while(choice != 4);

    return 0;
}
