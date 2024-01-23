#include<iostream>

using namespace std;
int n;
void swap(char *x, char *y)
{
    char temp;
    temp = *y;
    *y = *x;
    *x = temp;
}
void insert_array(char arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
}
int partition(char arr[], int low, int high)
{
    char pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++)
    {
        if (arr[j] >= pivot) // change this line
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quicksort(char arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi, high);
    }
}

void display(char arr[],int n)
{
    for (int j = 0; j < n; j++)
    {
        cout << arr[j] << " ";
    }
    cout << "\n";
}

int main() {
    // int n;
    char *arr = new char[n];

    cout<<"Enter the size of array : ";
    cin>>n;
    insert_array(arr,n);
    cout<<"Array before sorting";
    display(arr,n);

    quicksort(arr,0,n-1);
    cout<<"Array after sorting";
    display(arr,n);
    delete[]  arr;
    return 0;
}
