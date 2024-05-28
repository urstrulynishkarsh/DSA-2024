#include<iostream>
#include<stack>
#include<string.h>
#include<string>
using namespace std;

void ReverseString(string &str)
{
    stack<char> st;
    for(int i=0;i<str.length();i++)
    {
        st.push(str[i]);
    }
    while(!st.empty())
    {
        cout<<st.top();
        st.pop();
    }

}

int main()
{
    string str;
    cout<<"Enter the string: ";
    cin>>str;

    ReverseString(str);

}