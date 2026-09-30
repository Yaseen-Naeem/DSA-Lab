#include <iostream>
#include <string>
using namespace std;

class Stack{
    public:
    string tasks[100];
    int top;

    Stack(){
        top = -1;
    }

    void push(string task){
        if(top == 99){
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        tasks[top] = task;

        cout << task << " |  pushed into stack" << endl;
    }

    string pop(){
        if(top == -1){
            return " ";
        }
        string task = tasks[top];
        top--;

        return task;
    }

    string peek(){
        if(top == -1){
            return " ";
        }
        return tasks[top];
    }

    bool isEmpty(){
        return top == -1;
    }

    // Part A)
    void display(){
        if(isEmpty()){
            cout << "No pending tasks." << endl;
            return;
        }
        cout << "Pending tasks (top to bottom):" << endl;

        for(int i = top; i >= 0; i--){
            cout << top - i + 1 << ". " << tasks[i] << endl;
        }
    }

    // Part B)
    void undoLastTask(){
        if(isEmpty()){
            cout << "No task to remove." << endl;
            return;
        }
        string task = pop();
        cout << "Removed: " << task << endl;
    }

    // Part C)
    void search(string task){
        if(isEmpty()){
            cout << "No tasks in stack." << endl;
            return;
        }
        int above = 0;

        for(int i = top; i >= 0; i--){
            if(tasks[i] == task){
                cout << "Task found." << endl;
                cout << "Tasks above it: " << above << endl;
                return;
            }
            above++;
        }

        cout << "Task not found." << endl;
    }
};

int main(){
    Stack todo;
    int choice;
    string task;

    // Part D)
    do{
        cout << endl;
        cout << "1. Add Task" << endl;
        cout << "2. Remove Last Task" << endl;
        cout << "3. View All Tasks" << endl;
        cout << "4. Search Task" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter choice: ";
        cin >> choice;
        
        if(choice == 1){
            cout << "Enter task: ";
            getline(cin, task);
            cin.ignore();

            todo.push(task);
        }
        else if(choice == 2){
            todo.undoLastTask();
        }

        else if(choice == 3){
            todo.display();
        }

        else if(choice == 4){
            cout << "Enter task to search: ";
            getline(cin, task);

            todo.search(task);
        }
        else if(choice == 5){
            cout << "Exiting..." << endl;
        }
        else{
            cout << "Invalid choice." << endl;
        }
    } while(choice != 5);

    return 0;
}
