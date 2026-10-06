#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node* prev;
    Node* next;

    Node(int val)
    {
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    void displayForward()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->next != NULL)
                cout << " <-> ";

            temp = temp->next;
        }

        cout << endl;
    }

    void displayBackward()
    {
        Node* temp = tail;

        while (temp != NULL)
        {
            cout << temp->data;

            if (temp->prev != NULL)
                cout << " <-> ";

            temp = temp->prev;
        }

        cout << endl;
    }

    void insertAtStart(int val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    void insertAtEnd(int val)
    {
        Node* newNode = new Node(val);

        if (tail == NULL)
        {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }

    void insertAtPosition(int pos, int val)
    {
        if (pos == 0)
        {
            insertAtStart(val);
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        if (temp == tail)
        {
            insertAtEnd(val);
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        newNode->prev = temp;

        temp->next->prev = newNode;
        temp->next = newNode;
    }

    void deleteFromStart()
    {
        if (head == NULL)
            return;

        Node* temp = head;

        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
    }

    void deleteFromEnd()
    {
        if (tail == NULL)
            return;

        Node* temp = tail;

        if (head == tail)
        {
            head = NULL;
            tail = NULL;
        }
        else
        {
            tail = tail->prev;
            tail->next = NULL;
        }

        delete temp;
    }

    void deleteValue(int val)
    {
        Node* temp = head;

        while (temp != NULL)
        {
            if (temp->data == val)
            {
                if (temp == head)
                {
                    deleteFromStart();
                    return;
                }

                if (temp == tail)
                {
                    deleteFromEnd();
                    return;
                }

                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;

                delete temp;
                return;
            }

            temp = temp->next;
        }

        cout << "Value not found" << endl;
    }

    void reverse()
    {
        Node* temp = head;

        while (temp != NULL)
        {
            Node* nextNode = temp->next;

            temp->next = temp->prev;
            temp->prev = nextNode;

            temp = nextNode;
        }

        Node* tempHead = head;
        head = tail;
        tail = tempHead;
    }
};

int main()
{
    DoublyLinkedList list;

    list.insertAtEnd(10);
    list.insertAtEnd(30);
    list.insertAtPosition(1, 20);

    cout << "Forward: ";
    list.displayForward();

    cout << "Backward: ";
    list.displayBackward();

    list.insertAtStart(5);
    list.insertAtEnd(40);

    cout << "After insertion: ";
    list.displayForward();

    list.deleteFromStart();
    list.deleteFromEnd();
    list.deleteValue(20);

    cout << "After deletion: ";
    list.displayForward();

    list.reverse();

    cout << "After reverse: ";
    list.displayForward();

    return 0;
}
