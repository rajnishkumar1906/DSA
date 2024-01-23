#include <iostream>
using namespace std;

const int N = 6;
int front = -1;
int rear = -1;
int *queue = new int[N];

void enqueue(int x)
{
    if (rear == N - 1)
    {
        if (front == 0)
        {
            cout<<"Queue is full"<<endl;
        }
        else
        {
            rear = 0;
            queue[rear] = x;
        }
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        cout<<"Queue is empty"<<endl;
    }
    else if (front == rear)
    {
        cout<<"Dequeued element is "<<queue[front]<<endl;
        front = -1;
        rear = -1;
    }
    else
    {
        cout<<"Dequeued element is "<<queue[front]<<endl;
        front++;
        if (front == N)
        {
            front = 0;
        }
    }
}

void display()
{
    cout << "Queue is: ";
    if (front == -1 && rear == -1)
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        if (rear >= front)
        {
            for (int i = front; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        else
        {
            for (int i = front; i < N; i++)
            {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++)
            {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
}

int main()
{
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
