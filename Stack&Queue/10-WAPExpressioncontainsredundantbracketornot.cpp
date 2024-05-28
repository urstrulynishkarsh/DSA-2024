#include<iostream>
#include<stack>
#include<string.h>
#include<string>
using namespace std;

int checkRedundancy(string s) {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='('||ch=='+'||ch=='-'||ch=='*'||ch=='/')
            {
                st.push(ch);
            }
            else
            {
                if(ch==')')
                {
                    bool isreduntant=true;
                    while(st.top()!='(')
                    {
                        char chtop=st.top();
                        if(chtop=='+'||chtop=='-'||chtop=='*'||chtop=='/')
                        {
                            isreduntant=false;
                        }
                        st.pop();
                    }
                    if(isreduntant==true)
                    {
                        return true;
                    }
                    st.pop();
                }
            }
        }
        return false;
    }

int main()
{
    string s;
    cout<<"Enter the string of parenthesis: ";
    getline(cin,s);
    cout<<checkRedundancy(s);
}
