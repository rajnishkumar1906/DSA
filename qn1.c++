//There is an array .Calculate the sum of all even placed elements and
//also calculate the sum of all odd placed elements 
#include<iostream>
using namespace std;
int n;                                          //No. of houses
int *arr;
int maximumloot(int n)
{
    int pick = 0;
    int not_pick = 0;
    if(n<0)
    {
        return 0;
    }
    else if(n==0)
    {
        return arr[0];
    }
    
    pick = maximumloot(n-2) + arr[n-1];
    not_pick = maximumloot(n-2);
    return max(pick,not_pick);
}
int main() {
    // int n;
    cout<<"Enter the number of houses : ";
    cin>>n;             
    arr = new int[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    // without recursion
    int pick= 0;
    int j=0;
    while(j<n)
    {
        if(j%2==0)
        {
            pick += arr[j];
        }
        j++;
    }
    cout<<"Sum of even placed elements : "<<pick<<endl;
    int not_pick= 0;
    int k=1;
    while(k<n)
    {
        if(k%2!=0)
        {
            not_pick += arr[k];
        }
        k++;
    }
    cout<<"Sum of odd placed elements : "<<not_pick<<endl;
    int x = max(pick,not_pick);
    cout<<"Maximum loot : "<<x<<endl;


    //Recursion method
    int max = maximumloot(n);
    cout<<"Maximum loot : "<<max;
    return 0;
}