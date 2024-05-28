#include<iostream>
#include<stack>
#include<string.h>
#include<string>
using namespace std;

bool ValidParenthesis(string &s)
{
    stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='('||ch=='{'||ch=='[')
            {
                st.push(ch);
            }
            else
            {
                if(!st.empty())
                {
                    char chtop=st.top();
                    if(ch==')' && chtop=='(')
                    {
                        st.pop();
                    }
                    else if(ch=='}' && chtop=='{')
                    {
                         st.pop();
                    }
                    else if(ch==']' && chtop=='[')
                    {
                         st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
                else
                {
                    return false;
                }
            }
        }
        if(st.empty())
        {
            return true;
        }
        return false;
}

int main()
{
    string s;
    cout<<"Enter the string of parenthesis: ";
    getline(cin,s);

    cout<<ValidParenthesis(s);
}
