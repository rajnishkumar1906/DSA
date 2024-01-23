//Adding a node at kth position 
#include<iostream>
using namespace std;
int n;
struct node
{
    int data;
    node * link; 
};
node* head = NULL;
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

void  display1()
{
    node *ptr = head;
    while(ptr!=NULL)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->link;
    }
}

void add_node()
{
    node * NEW = new node;
    cout << "\nEnter the position: ";
    int k;
    cin >> k;
    cout << "\nEnter the new node data: ";
    cin >> NEW->data;

    if (k < 0 || k > n)
    {
        cout << "Invalid position." << endl;
        delete NEW;  // Clean up the newly created node.
        return;
    }

    if (k == 0)
    {
        NEW->link = head;
        head = NEW;
    }
    else
    {
        node * prev = NULL;
        node * current = head;
        for (int i = 0; i < k; i++)
        {
            prev = current;
            current = current->link;
        }
        NEW->link = current;
        prev->link = NEW;
    }
    n++; // Increment the count of nodes.
}

void  display2()
{
    node *ptr1 = head;
    while(ptr1!=NULL)
    {
        cout<<ptr1->data<<" ";
        ptr1 = ptr1->link;
    }
}
int main() {
    cout<<"Enter the number of nodes to be made for the linked list : "<<endl;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        insertion_end();
    }

    cout<<"Linked list before adding a node : ";
    display1();
    
    add_node();
    cout<<"\nLinked list after adding a node : ";
    display2();
    return 0;
}