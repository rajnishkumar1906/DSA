//Infix to postfix conversion

#include<iostream>
#include<stack>
#include<string>
using namespace std;
int precedence(char c)
{
    if(c == '^') return 5;
    else if(c == '*' || c == '/') return 2;
    else if(c == '+' || c == '-') return 1;
    else return 0;
}
int main()
{
    string infix;
    string postfix = "";                                                                  //We don't know the size of postfix.That's why we are adding the characters one by one to the postfix
    cout<<"Enter the infix  : ";
    cin>>infix;
    stack<char> st;
    st.push('('); 
    infix += ')';
    int i = 0;
    while(!st.empty())
    {
        char c = infix[i];
        
        if(c == '(')  st.push(c);
        
        else if( (c >= '0' && c<= '9') || (c >= 'A' && c<= 'Z') || (c >= 'a' && c<= 'z'))
            postfix += c;
            
        else if(c == ')')
        {
            while(st.top() != '(')
            {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
        
        else
        {
            while(precedence(st.top()) >= precedence(c))
            {
                postfix += st.top();
                st.pop();
            }
            st.push(c);
        }
        
        i++;
    }   
    cout<<"\nPostfix: "<<postfix;
    return 0;    
}