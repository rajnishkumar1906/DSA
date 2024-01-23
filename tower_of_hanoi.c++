//TOWER OF HANOI
//Recursion has been used here
//Implement tower of Hanoi concept and also find the numver of moves
#include<iostream>
using namespace std;
void TOH(int n,char src, char aux,char dest)
{
    int count=0;
    if(n==1)
    {
        cout<<n<<" moves from "<<src<<" to "<<dest<<endl;
    }
    else if(n==0)
    {
        return;
    }
    else
    {
        TOH(n-1,src,dest,aux);                                      //RECURSION WILL WORK HERE
        cout<<n<<" moves from "<<src<<" to "<<dest<<endl;
        TOH(n-1,aux,dest,src);                                      //RECURSION WILL WORK HERE
    }
}
int main() {
    int n;
    cout<<"Enter the number of discs: ";
    cin>>n;
    char src,aux,dest;
    cin>>src>>aux>>dest;
    TOH(n,src,aux,dest);
    return 0;
}