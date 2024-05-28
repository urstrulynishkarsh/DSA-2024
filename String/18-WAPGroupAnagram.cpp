#include<iostream>
#include<vector>
#include<cstring>
#include<string.h>
#include<map>
using namespace std;

void GroupAnaGram(vector<string> &v, vector<vector<string> > &ans)
{
   
    map<string,vector<string> > mp;

    for(auto str: v)
    {
        string s=str;
        sort(s.begin(),s.end());
        mp[s].push_back(str);
    }

    for(auto it=mp.begin();it!=mp.end();it++)
    {
        ans.push_back(it->second);
    }
}

int main(){
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;

    vector<string> v;
    cout<<"Enter the string in the Array: ";
    while(n--)
    {
        string input;
        cin>>input;
        v.push_back(input);
    }
    vector<vector<string> > ans;
    
    GroupAnaGram(v,ans);

    for(auto first:ans)
    {
        for(auto value:first)
        {
            cout<<value<<" ";
        }
        cout<<endl;
    }


    // for(auto val:v)
    // {
    //     cout<<val<<' ';
    // }
}