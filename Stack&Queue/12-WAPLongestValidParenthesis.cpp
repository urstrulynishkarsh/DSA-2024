#include<iostream>
#include<stack>
#include<string.h>
#include<string>
using namespace std;

   int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int maxLength=0;
        for(int i=0;i<s.length();i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                st.push(i);
            }
            else
            {
                st.pop();
                if(st.empty())
                {
                    st.push(i);
                }
                else
                {
                    // please remember this case
                    int len=i-st.top(); 
                    maxLength=max(len,maxLength);
                }
            }
        }
        return maxLength;
    }

int main()
{
    string s;
    cout<<"Enter the string of parenthesis: ";
    getline(cin,s);

    cout<<longestValidParentheses(s);
}
