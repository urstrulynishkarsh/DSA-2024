#include<iostream>
#include<vector>
#include<limits.h>
#include<set>
using namespace std;

void UnionOftwoArray(vector<int> &v1, vector<int> &v2,vector<int> &ans)
{
    set<int> st;
    for(int i=0;i<v1.size();i++)
    {
        st.insert(v1[i]);
    }
     for(int i=0;i<v2.size();i++)
    {
        st.insert(v2[i]);
    }
    for(auto val:st)
    {
        ans.push_back(val);
    }
}

int main()
{
    int n;
    cout<<"Enter the size of first array: ";
    cin>>n;
    vector<int> v1(n);
    cout<<"Enter the element in the first array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
     int m;
    cout<<"Enter the size of first array: ";
    cin>>m;
    vector<int> v2(m);
    cout<<"Enter the element in the first array: ";
    for(int i=0;i<m;i++)
    {
        cin>>v2[i];
    }
    vector<int> ans;
    UnionOftwoArray(v1,v2,ans); 
    for(auto val: ans)
    {
        cout<<val<<" ";
    }
}