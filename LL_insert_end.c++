// Implementation of linked list
// Insertion through end 
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
    node *ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr=ptr->link;
    }
}

int main(){
    cout<<"Enter the number of nodes  to be made for the linked list : "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        insertion_end();
    }
    cout<<"Linked list formed is :  ";
    display();
    return 0;
}