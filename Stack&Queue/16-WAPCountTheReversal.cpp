#include<iostream>
#include<stack>
#include<string.h>
#include<string>
using namespace std;

int countRev (string s)
{
    if(s.size()&1)
    {
        return -1;
    }
    stack<char> st;
    int ans=0;
    for(int i=0;i<s.length();i++)
    {
        char ch=s[i];
        if(ch=='{')
        {
            st.push(ch);
        }
        else
        {
            if(!st.empty() && st.top()=='{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    while(!st.empty())
    {
        char a=st.top();
        st.pop();
        char b=st.top();
        st.pop();
        if(a==b)
        {
            ans+=1;
        }
        else
        {
            ans+=2;
        }
    }
    return ans;
}

int main()
{
    string s;
    cout<<"Enter the string of parenthesis: ";
    getline(cin,s);

    cout<<countRev(s);
}
