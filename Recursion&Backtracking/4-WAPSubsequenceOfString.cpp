#include<iostream>
#include<vector>
using namespace std;

void Subsequence(string s, string output,int index,vector<string> &ans)
{
    if(index>=s.size())
    {
        ans.push_back(output);
        return;
    }

    // exclude
    Subsequence(s,output,index+1,ans);

    // include
   
    Subsequence(s,output+s[index],index+1,ans);
}

int main()
{
    string s="abc";
    string output;
    int index=0;
    vector<string> ans;

    Subsequence(s,output,index,ans);

    cout<<ans.size()<<endl;
    for(auto val: ans)
    {
        cout<<val<<" ";
    }
}