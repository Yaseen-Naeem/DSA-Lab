#include <iostream>
using namespace std;

class Node{

    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data){
        this-> data = data;
        next = NULL;
        prev = NULL;
    }

};

class Double{
    public:

    Node* head;
    Node* tail;

    Double(){
        head = NULL;
        tail = NULL;
    }

    void insertAtHead(int val){
        Node* n = new Node(val);

        if (head == NULL) {
            head = n;
            tail = n;
            return;
        }

        n->next = head;
        head->prev = n;
        head = n;
    }

    void insertAtTail(int val) {
        Node* n = new Node(val);

        if (tail == NULL) {
            head = n;
            tail = n;
            return;
        }

        tail->next = n;
        n->prev = tail;
        tail = n;
    }

    void insertAtPos(int pos, int val){
        if(pos == 0){
            insertAtHead(val);
            return;
        }

        Node* n = new Node(val);
        Node* curr = head;
        Node* pre = NULL;

        for(int i=0; i<pos && curr != NULL; i++){
            pre = curr;
            curr = curr->next;
        }

        if (curr == NULL) {
            insertAtTail(val);
            return;
        }

        n->next = pre->next; // Curr
        curr->prev = n; //points n;
        n->prev = pre; // n points to current's previous
        pre->next = n; // Last node points n
    }

    // Double Linked List Reverse

    void reverse() {
        if (head == NULL) return;

        Node* curr = head;
        Node* temp = NULL;

        while (curr != NULL) {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }

        temp = head;
        head = tail;
        tail = temp;
    }

    void display(){
        Node*temp = head;
        while(temp != NULL){
            cout << temp->data << "  ->  ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main(){
    Double list;

    list.insertAtPos(0, 10);
    list.insertAtPos(1, 20);
    list.insertAtPos(2, 30);
    list.insertAtPos(3, 40);
    list.insertAtPos(4, 50);

    cout << "\nLinked List : " << endl;
    list.display();

    list.reverse();
    cout << "Reversed Linked List Double: " << endl;
    list.display();

    return 0;
}