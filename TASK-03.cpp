#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node* next;
    node* prev;

    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class CDlinkedlist
{
public:
    node* head;
    node* tail;

    CDlinkedlist()
    {
        head = NULL;
        tail = NULL;
    }

    // Insert at end
    void insertAtEnd(int data)
    {
        node* newnode = new node(data);

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;

            head->next = head;
            head->prev = head;
        }
        else
        {
            newnode->prev = tail;
            newnode->next = head;

            tail->next = newnode;
            head->prev = newnode;

            tail = newnode;
        }
    }

    // Insert at beginning
    void insertAtBeginning(int data)
    {
        node* newnode = new node(data);

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;

            head->next = head;
            head->prev = head;
        }
        else
        {
            newnode->next = head;
            newnode->prev = tail;

            head->prev = newnode;
            tail->next = newnode;

            head = newnode;
        }
    }

    // Insert at given position
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

        node* temp = head;

        for (int i = 1; i < position - 1; i++)
        {
            temp = temp->next;

            if (temp == head)
            {
                cout << "Invalid position." << endl;
                return;
            }
        }

        node* newnode = new node(data);

        newnode->next = temp->next;
        newnode->prev = temp;

        temp->next->prev = newnode;
        temp->next = newnode;

        if (temp == tail)
        {
            tail = newnode;
        }
    }

    // Delete any node by value
    void deleteNode(int value)
    {
        if (head == NULL)
        {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;

        do
        {
            if (temp->data == value)
            {
                // Only one node
                if (head == tail)
                {
                    delete temp;
                    head = NULL;
                    tail = NULL;
                }
                else
                {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;

                    if (temp == head)
                    {
                        head = temp->next;
                    }

                    if (temp == tail)
                    {
                        tail = temp->prev;
                    }

                    delete temp;
                }

                return;
            }

            temp = temp->next;

        } while (temp != head);

        cout << "Node not found." << endl;
    }

    // Display complete circular doubly linked list
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

        cout << endl;
    }
};

int main()
{
    CDlinkedlist list;

    // Insert at end
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);

    cout << "After inserting at end: ";
    list.display();

    // Insert at beginning
    list.insertAtBeginning(5);

    cout << "After inserting at beginning: ";
    list.display();

    // Insert at position
    list.insertAtPosition(15, 3);

    cout << "After inserting 15 at position 3: ";
    list.display();

    // Delete any node
    list.deleteNode(20);

    cout << "After deleting 20: ";
    list.display();

    return 0;
}