#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};

class Single {
public:
    Node* head;

    Single() {
        head = NULL;
    }

    void insertAtHead(int val) {
        Node* n = new Node(val);
        n->next = head;
        head = n;
    }

    void insertAtTail(int val) {
        Node* n = new Node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }

    void insertAtPos(int pos, int val) {
        Node* curr = head;
        for (int i = 0; i < pos && curr != NULL; i++) {
            curr = curr->next;
        }

        if (curr == NULL) {
            cout << "Position out of range!\n";
            return;
        }

        Node* n = new Node(val);
        n->next = curr->next;
        curr->next = n;
    }

    int search(int key) {
        Node* temp = head;
        int pos = 0;
        while (temp != NULL) {
            if (temp->data == key) return pos;
            temp = temp->next;
            pos++;
        }
        return -1;
    }

    int countNodes() {
        int count = 0;
        Node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    int sumOfNodes() {
        int sum = 0;
        Node* temp = head;
        while (temp != NULL) {
            sum += temp->data;
            temp = temp->next;
        }
        return sum;
    }

    void deleteAtHead() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    void deleteAtTail() {
        if (head == NULL) {
            cout << "List is empty!\n";
            return;
        }
        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }
        Node* curr = head;
        Node* prev = NULL;
        while (curr->next != NULL) {
            prev = curr;
            curr = curr->next;
        }
        prev->next = NULL;
        delete curr;
    }

    void deleteAtPos(int pos) {
        Node* curr = head;
        for (int i = 0; i < pos && curr != NULL; i++) {
            curr = curr->next;
        }

        if (curr == NULL || curr->next == NULL) {
            cout << "No node exists to delete after " << pos << "!\n";
            return;
        }

        Node* toDelete = curr->next;
        curr->next = toDelete->next;
        delete toDelete;
    }

    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    // Linked List Reversal
    void reverse() {
        Node* prev = NULL;
        Node* curr = head;
        Node* nextNode = NULL;

        while (curr != NULL) {
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        head = prev;
    }
};

int main() {
    Single list;
    int choice, val, pos;

    while (true) {
        cout << "\n--- LINKED LIST MENU ---\n";
        cout << "1. Insert at Start\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert After Position\n";
        cout << "4. Search Key\n";
        cout << "5. Count Nodes & Sum\n";
        cout << "6. Delete from Start\n";
        cout << "7. Delete from End\n";
        cout << "8. Delete After Position\n";
        cout << "9. Reverse List\n";
        cout << "10. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtHead(val);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> val;
                list.insertAtTail(val);
                break;

            case 3:
                cout << "Enter position and value: ";
                cin >> pos >> val;
                list.insertAtPos(pos, val);
                break;

            case 4:
                cout << "Enter key to search: ";
                cin >> val;
                pos = list.search(val);
                if (pos != -1) cout << "Found at position: " << pos << endl;
                else cout << "Key not found!\n";
                break;

            case 5:
                cout << "Total Nodes: " << list.countNodes() << endl;
                cout << "Sum of Nodes: " << list.sumOfNodes() << endl;
                break;

            case 6:
                list.deleteAtHead();
                break;

            case 7:
                list.deleteAtTail();
                break;

            case 8:
                cout << "Enter position: ";
                cin >> pos;
                list.deleteAtPos(pos);
                break;

            case 9:
                list.reverse();
                cout << "List reversed.\n";
                break;

            case 10:
                list.display();
                break;

            case 0:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}