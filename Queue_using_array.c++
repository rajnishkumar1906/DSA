//Implementation of queue using array
#include<iostream>
using namespace std;
int N;
#define N 6
int front = -1;
int rear = -1;
int * queue = new int[N];
void enqueue(int x)
{
    if(rear == N-1)
    {
        cout<<"Queue is full"<<endl;
    }
    else 
    {
        if(front = -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = x;
    }

}
void dequeue()
{
    if(front == -1 && rear ==-1)
    {
        cout<<"Queue is empty";
    }
    else if(front == rear)
    {
        cout<<"Dequed element is "<<queue[front]<<endl;
        front = -1;
        rear = -1;
    }
    else
    {
        cout<<"Dequed element is "<<queue[front]<<endl;
        front++;
    }
}
void display()
{
    cout<<"Queue is : ";
    if(front == -1 && rear == -1)
    {
        cout<<"Queue is empty";
    }
    else
    {
        for(int i=front;i<rear+1;i++)
        {
            cout<<queue[i]<<" ";
        }
    }
}
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    dequeue();
    dequeue();
    
    display();
    return 0;
}