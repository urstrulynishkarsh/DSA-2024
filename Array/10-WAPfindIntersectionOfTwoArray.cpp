#include<iostream>
#include<vector>
#include<limits.h>
#include<set>
using namespace std;

void IntersectionOftwoArray(vector<int> &v1, vector<int> &v2,vector<int> &ans)
{
        set<int> st;
        set<int> st2;
        for(auto ele: v2)
        {
            st.insert(ele);
        }
        for(auto ele: v1)
        {
            if(st.find(ele)!=st.end())
            {
                st2.insert(ele);
            }
        }
        for(auto i:st2)
        {
            ans.push_back(i);
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
    IntersectionOftwoArray(v1,v2,ans); 
    for(auto val: ans)
    {
        cout<<val<<" ";
    }
}