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

class linkedlist
{
public:
    node* head;
    node* tail;

    linkedlist()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtEnd(int data)
    {
        node* newnode = new node(data);

        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = newnode;
        }
    }

    void display()
    {
        node* temp = head;

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }

    void arrangeEvenOdd()
    {
        node* evenHead = NULL;
        node* evenTail = NULL;

        node* oddHead = NULL;
        node* oddTail = NULL;

        node* temp = head;

        while (temp != NULL)
        {
            node* nextNode = temp->next;
            temp->next = NULL;

            if (temp->data % 2 == 0)
            {
                if (evenHead == NULL)
                {
                    evenHead = temp;
                    evenTail = temp;
                }
                else
                {
                    evenTail->next = temp;
                    evenTail = temp;
                }
            }
            else
            {
                if (oddHead == NULL)
                {
                    oddHead = temp;
                    oddTail = temp;
                }
                else
                {
                    oddTail->next = temp;
                    oddTail = temp;
                }
            }

            temp = nextNode;
        }

        // When there will be no even numbers....
        if (evenHead == NULL)
        {
            head = oddHead;
            tail = oddTail;
            return;
        }

        // Where there will be no odd numbers...
        if (oddHead == NULL)
        {
            head = evenHead;
            tail = evenTail;
            return;
        }

        // Joining the even list with odd list....
        evenTail->next = oddHead;

        head = evenHead;
        tail = oddTail;
    }
};

int main()
{
    linkedlist list;

    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;

        list.insertAtEnd(x);
    }

    cout << "\nOriginal List: ";
    list.display();

    list.arrangeEvenOdd();

    cout << "Modified List: ";
    list.display();

    return 0;
}