#include<iostream>
#include<cstring>
#include<string.h>
#include<vector>
using namespace std;

string LongestCommonPrefix(vector<string> &v)
{
    sort(v.begin(),v.end());
    string first=v[0];
    string last=v[v.size()-1];
    string ans;
    for(int i=0;i<last.length();i++)
    {
        if(first[i]==last[i])
        {
            ans.push_back(last[i]);
            cout<<ans;
        }
        else{
            break;
        }
    }
    return ans;
}


int main(){
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;

    vector<string> v(n);

    cout<<"Enter the string in the vector: ";
    while(n--)
    {
        string input;
        cin>>input;
        v.push_back(input);
    }
    cout<<LongestCommonPrefix(v);
}