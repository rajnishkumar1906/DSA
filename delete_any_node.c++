//Deletion of any node from any position
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
    cout<<"Initial Linked list : ";
    node *ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
}
void delete_node(int x)
{
    node * ptr  = head;
    node * prev = NULL;
    if(x<=0 || x>n)
    {
        cout<<"Invalid position provided.";
    }
    else if(x==1)
    {
        head = NULL;
    }
    else
    {
        int i=1;
        while(i<x)
        {
            prev = ptr;
            ptr = ptr -> link;
            i++;
        }
        prev->link = ptr->link;
        delete ptr;
    }
    n--;
}
void final_node()
{
    cout<<"Final Linked list : ";
    node *pointer = head;
    while(pointer!=NULL)
    {
        cout<<pointer->data<<" ";
        pointer=pointer->link;
    }
}
int main() 
{
    cout<<"Enter the no. of nodes : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        insertion_end();
    }
    display();
    int k;
    cout<<"\nEnter the node number to be deleted : ";
    cin>>k;
    delete_node(k);
    final_node();
    return 0;
}