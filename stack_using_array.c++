//Stack  :  Collection of elements of sama data types / LIFO 
//Stack implementation using array
#include<iostream>
using namespace std;
int n;
int top = -1;
int *arr;
//push function : Adding the element to the stack 
void push(int x) {
    if (top == (n-1)){
        cout << "Stack Overflow\n";
    } 
    else {
        top++;
        arr[top] = x; // Corrected this line
    }
}
//pop function : Removing an element fromthe stack
void pop() {
    if (top == -1) {
        cout << "Stack is empty\n";
    } else {
        top--;
    }
}
void display() {
    cout << "Final stack: ";
    for (int i = 0; i <= top; i++) { 
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main() {
    cout << "Enter the size of the stack: ";
    cin >> n;
    arr = new int[n];
    push(1);
    push(2);
    push(3);
    push(4);
    push(5);
    pop();
    pop();
    pop();
    display();
    return 0;
}