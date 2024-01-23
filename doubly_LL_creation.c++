//Doubly linked list creation
#include<iostream>
using namespace std;
struct node
{
    int data;
    node*prev;
    node*next;
};
int n;
node* head = NULL;
void create()
{
    node*NEW = new node;
    cout<<"Enter the data : ";
    cin>>NEW->data;
    NEW->prev = NULL;
    NEW->next = NULL;
    if(head == NULL)
    {
        // NEW->prev = head;
        head = NEW;
    }
    else
    {
        // NEW->prev = head;                                          //backward listing
        // head->next = NEW;
        // head = NEW;


        node*current = head;                                         //forward listing
        while(current->next!=NULL)
        {
            current = current->next;
        }   
        NEW->prev = current;
        current->next = NEW;
    }
}
void display()
{
    node * ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->next;
    }

}
int main() {
    cout<<"Enter the number of nodes : ";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        create();
    }
    cout<<"Linked list made : ";
    display();
    return 0;
}