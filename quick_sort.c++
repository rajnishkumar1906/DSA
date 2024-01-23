#include<iostream>
using namespace std;
int n;
int * arr = new int[n];
void insert_array()
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
void swap(int*x,int*y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int arr[],int low,int high)
{
    int pivot = arr[high];
    int i = low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);
    return i+1;
}

void quick_sort(int arr[],int low,int high)                            
{
    if(low<high)
    {
        int pi = partition(arr,low,high);
        quick_sort(arr,low,pi-1);
        quick_sort(arr,pi+1,high);
    }
}
void display()
{
    for(int j=0;j<n;j++)
    {
        cout<<arr[j]<<" ";
    }
    cout<<"\n";
}
int main() {
    cout<<"Enter the size of array : ";
    cin>>n;
    insert_array();
    cout<<"Array before sorting";
    display();

    quick_sort(arr,0,n-1);
    cout<<"Array after sorting";
    display();
    delete[]  arr; 
    return 0;
}