//Deletion of node from beginning of a linked list

#include<iostream>
using namespace std;
int n;
struct node
{
    int data;
    node * next; 
};
node* head = NULL;
void insertion_end()
{
    node * NEW = new node;
    NEW->next= NULL;
    cout<<"Enter the data : "<<endl;
    cin>>NEW->data;
    if(head==NULL)
    {
        head = NEW;
    }
    else
    {
        node * current = head;
        while(current->next !=  NULL)
        {
            current = current->next;
        }
        current->next = NEW;
    }
}

void  display1()
{
    cout<<"Linked list before deletion : ";
    node *ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}
void delete_firstnode()
{
    if(head==NULL)
    {
        cout<<"Linked list is empty."<<endl;
    }
    else
    {
        // node * ptr = NULL;                          //<--First Method
        // ptr = head->next;
        // head = ptr;
        // n--;

        node* temp = head;                             //<--Second method
        head = head->next;
        delete temp;
    }
}
void display2()
{
    cout<<"\nLinked list aftre deletion of first node : ";
    node *ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}
int main() {
    cout<<"Enter the number of nodes to be mode for LL : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        insertion_end();
    }
    display1();
    delete_firstnode();
    display2();
    return 0;
}