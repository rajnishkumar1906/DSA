#include<iostream>
#define N 100
using namespace std;
int * arr;                                                      //This is a pointer used to store data as it's using dynamic memory allocation method
int main() {
    arr = new int[N];
    int h;
    cout<<"Enter the height of tree ";
    cin>>h;
    int i = 1;
    while(i<=h)
    {
        cin>>arr[i];
        cin>>arr[2*i];
        cin>>arr[2*i + 1];
        i++;
    }
    i=1;
    while(i<=h)
    {
        cout<<arr[i]<<" ";
        cout<<arr[2*i]<<" ";
        cout<<arr[2*i + 1]<<" ";
        i++;
    }
    return 0;
}