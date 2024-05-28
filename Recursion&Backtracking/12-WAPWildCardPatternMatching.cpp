#include<iostream>
#include<string>
#include<string.h>
using namespace std;

bool WildCardPattern(string s, string p, int si, int pi)
{
    // base case
    if(si==s.size() && pi==p.size())
    {
        return true;
    }
    if(si==s.size() && pi<p.size())
    {
        while(pi<p.size())
        {
            if(p[pi]!='*')
            {
                return false;
            }
            pi++;
        }
        return true;
    }

    // solution if bith equal
    if(s[si]==p[pi]||'?'==p[pi])
    {
        return WildCardPattern(s,p,si+1,pi+1);
    }
    if(p[pi]=='*')
    {
        bool case1=WildCardPattern(s,p,si,pi+1);
        bool case2=WildCardPattern(s,p,si+1,pi);
        return case1||case2;
    }
    return false;

}

int main(){
    string str1;
    cout<<"Enter the first string: ";
    getline(cin,str1);
     string str2;
    cout<<"Enter the first string: ";
    getline(cin,str2);

    int si=0;
    int pi=0;
   
    cout<<WildCardPattern(str1,str2,si,pi);
}