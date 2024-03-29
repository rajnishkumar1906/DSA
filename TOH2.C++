//count the number of moves
#include<iostream>
using namespace std;
int ToH(int n,char src,char dest,char aux){
    int count=0;
    if(n==1){
        cout<<"move the "<<n<<" from "<<src<<" to "<<dest<<endl;
        return 1;
    }
    if(n==0){
        return 0;
    }
    count+=ToH(n-1,src,aux,dest);
    cout<<"move the "<<n<<" from "<<src<<" to "<<dest<<endl;
    count++;
    count+=ToH(n-1,aux,dest,src);
    return count;
}
int main(){
    int n;
    cin>>n;
    char src,dest, aux;
    cin>>src>>dest>>aux;
    int moves=ToH(n,src,dest,aux);
    cout<<"No. of moves used : "<<moves<<endl;
}