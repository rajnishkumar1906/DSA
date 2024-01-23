#include<iostream>
using namespace std;
struct node
{
    int data;
    node* link;
};

node* head = NULL;

void insertion()
{
    node* NEW = new node;
    NEW->link = NULL;
    cout << "Enter the data: ";
    cin >> NEW->data;
    if (head == NULL)
    {
        NEW->link = NEW; // Point to itself in a circular list
        head = NEW;
    }
    else
    {
        node* current = head;
        while (current->link != head)
        {
            current = current->link;
        }
        current->link = NEW;
        NEW->link = head;
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "Linked List is empty" << endl;
        return;
    }

    node* ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    } while (ptr != head);
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of nodes to be made: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        insertion();
    }
    display();
    return 0;
}
