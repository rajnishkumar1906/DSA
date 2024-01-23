// Merge sort using recursion
#include <iostream>
using namespace std;
void mergesort(int arr[], int l, int r)
{

    if (l < r)
    {
        int mid = (l + r) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        
        merge(arr, l, mid);
        merge(arr, mid + 1, r);
    }
}
void merge(int arr[], int l, int r)
{
    int mid = (l+r)/2;
    int i=0,j=0,k=0;
    int m,n;
    m = mid-l+1;
    m = r-mid;
    int a[m],b[n];
    while(i<m+n)
    {
        while(j<m)
        {
            while(k<n)
            {
                if(a[j]<=b[k])
                {
                    arr[i] = a[j];
                    i++;j++;
                }
                else
                {
                    arr[i] = b[k];
                    i++;k++;
                }
            }
        }
    }
}
int main()
{
    int arr[] = {};
    int num;
    cout<<"Enter the number of elements of the array: ";
    cin>>num;
    for(int p = 0;p<num;p++)
    {
        cin>>arr[p];
    }
    int l = 0,r = num-1;
    mergesort(arr,l,r);
    cout<<"Final sorted array is : ";
    for(int p = 0;p<num;p++)
    {
        cin>>arr[p];
    }

    return 0;
}