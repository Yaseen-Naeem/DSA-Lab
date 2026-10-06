#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    string data;
    Node* next;

    Node(string value)
    {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList
{
private:
    Node* head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }

    void append(string val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
            temp = temp->next;

        temp->next = newNode;
        newNode->next = head;
    }

    void display()
    {
        if (head == NULL)
            return;

        Node* temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while (temp != head);

        cout << endl;
    }

    void insert(int pos, string val)
    {
        Node* newNode = new Node(val);

        if (head == NULL)
        {
            head = newNode;
            newNode->next = head;
            return;
        }

        if (pos == 0)
        {
            Node* temp = head;

            while (temp->next != head)
                temp = temp->next;

            newNode->next = head;
            temp->next = newNode;
            head = newNode;
            return;
        }

        Node* temp = head;

        for (int i = 0; i < pos - 1; i++)
            temp = temp->next;

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void deleteValue(string val)
    {
        if (head == NULL)
            return;

        if (head->data == val)
        {
            if (head->next == head)
            {
                delete head;
                head = NULL;
                return;
            }

            Node* temp = head;

            while (temp->next != head)
                temp = temp->next;

            Node* deleteNode = head;
            head = head->next;
            temp->next = head;

            delete deleteNode;
            return;
        }

        Node* temp = head;

        while (temp->next != head)
        {
            if (temp->next->data == val)
            {
                Node* deleteNode = temp->next;
                temp->next = deleteNode->next;
                delete deleteNode;
                return;
            }

            temp = temp->next;
        }
    }

    bool search(string key)
    {
        if (head == NULL)
            return false;

        Node* temp = head;

        do
        {
            if (temp->data == key)
                return true;

            temp = temp->next;
        }
        while (temp != head);

        return false;
    }

    void roundRobin(int turns)
    {
        if (head == NULL)
            return;

        Node* current = head;

        for (int i = 0; i < turns; i++)
        {
            cout << current->data << " ";
            current = current->next;
        }

        cout << endl;
    }
};

int main()
{
    CircularLinkedList players;

    players.append("Ali");
    players.append("Beena");
    players.append("Cara");

    cout << "Players: ";
    players.display();

    players.insert(1, "Dani");

    cout << "After insertion: ";
    players.display();

    players.deleteValue("Dani");

    cout << "After deletion: ";
    players.display();

    cout << "Search Beena: ";
    if (players.search("Beena"))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    cout << "Round Robin: ";
    players.roundRobin(6);

    return 0;
}
