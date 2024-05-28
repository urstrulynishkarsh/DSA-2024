#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

void  Generate(int n, vector<string> &ans, int open, int close,string output)
{
    if(open==0 && close==0)
    {
        ans.push_back(output);
        return;
    }
    if(open>0)
    {
        Generate(n,ans,open-1,close,output+'(');
    }
    if(close>open)
    {
         Generate(n,ans,open,close-1,output+')');
    }
}

int main(){
    int n;
    cout<<"Enter the number to generate parenthesis: ";
    cin>>n;
    vector<string> ans;
       int open=n;
       int close=n;
       string output;
       Generate(n,ans,open,close,output);
       for(auto val:ans)
       {
        cout<<val<<" ";
       }
  
 

}