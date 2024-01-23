#include <iostream>
using namespace std;
struct node
{
    int data;
    node *link;
};
node *head = NULL;
void insert_node(int d)          //Insertion from end
{
    node*NEW = new node;
    NEW->data = d;
    NEW->link = NULL;
    if(head == NULL)
    {
        head = NEW;
    }
    else
    {
        node*current = head;
        while(current->link != NULL)
        {
            current = current->link;
        }
        current->link = NEW;
    }
}
void display()
{
    node*ptr = head;
    if(head==NULL)
    {
        cout<<"Linked List is empty";
    }
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }
}
int main()
{
    int data;
    display();
    return 0;
}