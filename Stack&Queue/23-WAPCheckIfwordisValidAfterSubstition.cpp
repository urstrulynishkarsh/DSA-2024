#include<iostream>
#include<stack>
#include<string.h>
using namespace std;



bool isValid(string s) {
        if(s[0]!='a')
        {
            return false;
        }
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='a')
            {
                st.push(ch);
            }
            else if(ch=='b')
            {
                if(!st.empty() && st.top()=='a')
                {
                    st.push(ch);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                if(!st.empty() && st.top()=='b')
                {
                    st.pop();
                     if(!st.empty() && st.top()=='a')
                    {
                        st.pop();
                     }
                }
                else
                {
                    return false;
                }
            }
        }
        return st.empty();
    }

    int main()
{
    string path;
    cout<<"Enter the path of the string: ";
    getline(cin,path);

   cout<<isValid(path);
}