//Stack implementation using Linked List
#include<iostream>
using namespace std;
struct node
{
    int data;
    node * link;
};

node * head = NULL;

void push(int n)
{
    node * NEW = new node;
    NEW->data = n;
    NEW->link = head;;
    head = NEW;
}
void pop()
{
    if(head == NULL)
    {
        cout<<"Stack is empty"<<endl;
    }
    else
    {
        node * temp = head;
        head = head->link;
        delete temp;
    }
}
void display()
{
    cout<<"Formed Linked List is : ";
    node * ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr -> link;
    }
    cout<<endl;
}
int main() {
    push(12);
    push(13);
    push(14);
    push(15);
    push(16);
    display();
    pop();
    pop();
    pop();
    pop();
    pop();
    pop();
    display();
    return 0;
}