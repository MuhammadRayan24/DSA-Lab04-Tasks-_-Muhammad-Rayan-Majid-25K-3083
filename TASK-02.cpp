#include<iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Clinkedlist
{
public:
    node* head;
    node* tail;

    Clinkedlist()
    {
        head = NULL;
        tail = NULL;
    }

    // Insert at the end of the list..
    void insertAtEnd(int data)
    {
        node* newnode = new node(data);

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            tail->next = head;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
            tail->next = head;
        }
    }

    // Insert at the beginning of the list...
    void insertAtBeginning(int data)
    {
        node* newnode = new node(data);

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
            tail->next = head;
        }
        else
        {
            newnode->next = head;
            head = newnode;
            tail->next = head;
        }
    }

    // Insert at the given position in list...
    void insertAtPosition(int data, int position)
    {
        if (position < 1)
        {
            cout << "Invalid position." << endl;
            return;
        }

        if (position == 1)
        {
            insertAtBeginning(data);
            return;
        }

        node* newnode = new node(data);
        node* temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;

            if (temp == head)
            {
                cout << "Invalid position." << endl;
                delete newnode;
                return;
            }
        }

        newnode->next = temp->next;
        temp->next = newnode;

        if (temp == tail)
        {
            tail = newnode;
        }

        tail->next = head;
    }

    // Deleting any node by value....
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        // When deleting the head..
        if (head->data == value)
        {
            if (head == tail)
            {
                delete head;
                head = NULL;
                tail = NULL;
            }
            else
            {
                node* temp = head;
                head = head->next;
                tail->next = head;
                delete temp;
            }

            return;
        }

        node* temp = head;

        while (temp->next != head)
        {
            if (temp->next->data == value)
            {
                node* deleteNode = temp->next;

                temp->next = deleteNode->next;

                if (deleteNode == tail)
                {
                    tail = temp;
                }

                tail->next = head;

                delete deleteNode;
                return;
            }

            temp = temp->next;
        }

        cout << "Node not found." << endl;
    }

    // Displaying the circular linked list....
    void display()
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;

        do
        {
            cout << temp->data << " ";
            temp = temp->next;

        } while (temp != head);

        cout << "HEAD" << endl;
    }
};

int main()
{
    Clinkedlist list;

    // Inserting at end
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "After inserting at end: ";
    list.display();

    // Inserting at beginning
    list.insertAtBeginning(5);

    cout << "After inserting at beginning: ";
    list.display();

    // Inserting at certain position
    list.insertAtPosition(15, 3);

    cout << "After inserting 15 at position 3: ";
    list.display();

    // Deleting the node
    list.deleteNode(20);

    cout << "After deleting 20: ";
    list.display();

    return 0;
}