#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
void Reverse(stack<string> &st,string &ans)
    {
        if(st.empty())
        {
            return;
        }
        string minPath=st.top();
        st.pop();
        Reverse(st,ans);
        ans+=minPath;
    }
    string simplifyPath(string path) {
        stack<string> st;
        int i=0;
        while(i<path.length())
        {
            int s=i;
            int e=i+1;
            while(e<path.length() && path[e]!='/')
            {
                e++;
            }
            string minPath=path.substr(s,e-s);
            i=e;
            if(minPath=="/" || minPath=="/.")
            {
                continue;
            }
            if(minPath!="/..")
            {
                st.push(minPath);
            }
            else if(!st.empty())
            {
                st.pop();
            }
        }
        string ans=st.empty()?"/":"";
        cout<<ans<<"My section "<<endl;
        Reverse(st,ans);
        return ans;
    }

int main()
{
    string path;
    cout<<"Enter the path of the string: ";
    getline(cin,path);

   cout<<simplifyPath(path);
}