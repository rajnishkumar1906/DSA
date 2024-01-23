#include<iostream>
using namespace std;
struct node
{
    int data;
    node * link;
};
node* head = NULL;                                   //helps in deletion of node
node* tail = NULL;                                   //helps in insertion of node
void enqueue(int x)                                  //There is no overflow in linked list 
{                                                    //complexity is O(1)
    node*NEW = new node;
    NEW->data = x;
    NEW->link = NULL;
    if(head==NULL)
    {
        head = NEW;
        tail = NEW;
    }
    else
    {
        tail->link = NEW;
        tail = NEW;
    }
}
void dequeue()                                                   //complexity is O(1)
{           
    if(head == NULL && tail == NULL)                             //Empty queue condition
    {
        cout<<"Queue is empty\n";
    }
    else if(head==tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        node * ptr = head;
        head = head->link;
        delete ptr;
    }
}
void display()
{
    node *ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();

    display();
    return 0;
}