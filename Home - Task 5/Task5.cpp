#include <iostream>
using namespace std;

class Stack{
    private:
    int arr[100];
    int top;

    public:
    Stack(){
        top = -1;
    }

    void push(int x){
        arr[++top] = x;
    }

    int pop(){
        return arr[top--];
    }

    bool isEmpty(){
        return top == -1;
    }
};

class Queue{
    private:
    Stack stackIn;
    Stack stackOut;

    public:
    void enqueue(int x){
        stackIn.push(x);
    }

    int dequeue(){
        if (stackOut.isEmpty()){
            while (!stackIn.isEmpty())
                stackOut.push(stackIn.pop());
        }

        return stackOut.pop();
    }
};

int main(){
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    cout << q.dequeue() << " ";

    q.enqueue(4);

    cout << q.dequeue() << " ";
    cout << q.dequeue() << " ";
    cout << q.dequeue();

    return 0;
}