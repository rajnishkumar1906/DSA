//Deletion of node from end of a linked list
#include<iostream>
using namespace std;

struct node
{
    int data;
    node * link;
};
int n;
node *  head = NULL;
void insertion_end()
{
    node * NEW = new node;
    NEW->link= NULL;
    cout<<"Enter the data : "<<endl;
    cin>>NEW->data;
    if(head==NULL)
    {
        head = NEW;
    }
    else
    {
        node * current = head;
        while(current->link !=  NULL)
        {
            current = current->link;
        }
        current->link = NEW;
    }
}
void display()
{
    cout<<"Linked list formed : ";
    node *ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
}
void delete_end_node()
{
    node*ptr = head;
    node*prev = NULL;
    while(ptr->link!=NULL)
    {
        prev = ptr;
        ptr = ptr -> link;
    }
    delete ptr;
    prev->link = NULL;
    n--;
}
void final_LL()
{
    cout<<"\nNew linked list formed : ";
    node *ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
}
int main() {
    cout<<"Enter the no. of nodes : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        insertion_end();
    }
    display();
    delete_end_node();
    final_LL();
    return 0;
}