#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class CircularLinkedList
{
public:
    Node* head;
    Node* tail;

    CircularLinkedList()
    {
        head = NULL;
        tail = NULL;
    }

    // Task 5: Display each node exactly once
    void display()
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while(temp != head);

        cout << endl;
    }

    // Task 6: Add node at end
    void append(int val)
    {
        Node* newNode = new Node(val);

        if(head == NULL)
        {
            head = newNode;
            tail = newNode;
            tail->next = head;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
            tail->next = head;
        }
    }

    // Task 6: Insert at a 0-indexed position
    void insert(int pos, int val)
    {
        if(pos < 0)
        {
            cout << "Invalid position" << endl;
            return;
        }

        if(pos == 0)
        {
            Node* newNode = new Node(val);

            if(head == NULL)
            {
                head = newNode;
                tail = newNode;
                tail->next = head;
            }
            else
            {
                newNode->next = head;
                head = newNode;
                tail->next = head;
            }

            return;
        }

        Node* temp = head;

        for(int i = 0; i < pos - 1 && temp != tail; i++)
        {
            temp = temp->next;
        }

        if(temp == tail && pos > 1)
        {
            cout << "Invalid position" << endl;
            return;
        }

        Node* newNode = new Node(val);

        newNode->next = temp->next;
        temp->next = newNode;

        if(temp == tail)
        {
            tail = newNode;
            tail->next = head;
        }
    }

    // Task 6: Delete first node containing val
    void deleteValue(int val)
    {
        if(head == NULL)
        {
            cout << "List is empty" << endl;
            return;
        }

        Node* temp = head;
        Node* prev = tail;

        do
        {
            if(temp->data == val)
            {
                if(head == tail)
                {
                    head = NULL;
                    tail = NULL;
                }
                else
                {
                    prev->next = temp->next;

                    if(temp == head)
                    {
                        head = temp->next;
                        tail->next = head;
                    }

                    if(temp == tail)
                    {
                        tail = prev;
                        tail->next = head;
                    }
                }

                delete temp;
                return;
            }

            prev = temp;
            temp = temp->next;
        }
        while(temp != head);

        cout << "Value not found" << endl;
    }

    // Task 6: Search for a value
    bool search(int key)
    {
        if(head == NULL)
            return false;

        Node* temp = head;

        do
        {
            if(temp->data == key)
                return true;

            temp = temp->next;
        }
        while(temp != head);

        return false;
    }
};

int main()
{
    CircularLinkedList list;

    list.append(10);
    list.append(30);
    list.insert(1, 20);

    cout << "List: ";
    list.display();

    list.deleteValue(20);

    cout << "After deleting 20: ";
    list.display();

    if(list.search(30))
        cout << "30 found" << endl;
    else
        cout << "30 not found" << endl;

    return 0;
}