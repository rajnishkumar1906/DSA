#include<iostream>
using namespace std;
int n;
struct node
{
    int data;
    node * next; 
};
node* head = NULL;
void insertion_beg()
{
    node *NEW = new node;
    cout<<"Enter the data : "<<endl;
    cin>>NEW->data;
    if(head == NULL)
    {
        NEW->next = NULL;
        head = NEW;
    }
    else
    {
        NEW->next = head;
        head = NEW;
    }
}

void  display()
{
    node *ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }
}
int main() {
    cout<<"Enter the number of nodes to be made for the linked list : "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        insertion_beg();
    }

    display();
    return 0;
}