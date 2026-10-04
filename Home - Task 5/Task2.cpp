#include <iostream>
using namespace std;

class Queue{
    private:
    int front;
    int rear;
    int arr[5];

    public:

    Queue(){
        front = -1;
        rear = -1;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return rear == 4;
    }

    void enqueue(int value){
        if (isFull()){
            cout << "Queue is full" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        arr[rear] = value;
    }

    void dequeue(){
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Dequeued: " << arr[front] << endl;

        if (front == rear){
            front = -1;
            rear = -1;
        }else
            front++;
    }
};

int main(){
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    q.dequeue();
    q.dequeue();
    q.dequeue();

    q.enqueue(60);
    q.enqueue(70);

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();

    return 0;
}