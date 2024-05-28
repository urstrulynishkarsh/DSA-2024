#include<iostream>
#include<vector>
#include<deque>
using namespace std;


vector<int> printFirstNegativeInteger(vector<int> &v, int n, int k)
{
    vector<int> ans;
    deque<int> dq;
    for(int i=0;i<k;i++)
    {
        if(v[i]<0)
        {
            dq.push_back(i);
        }
    }
    for(int i=k;i<n;i++)
    {
        if(dq.empty())
        {
            ans.push_back(0);
        }
        else{
            ans.push_back(v[dq.front()]);
        }
        while(!dq.empty() && (i-dq.front())>=k)
        {
            dq.pop_front();
        }
       if(v[i]<0)
        {
            dq.push_back(i);
        }
    }
     if(dq.empty())
        {
            ans.push_back(0);
        }
        else{
            ans.push_back(v[dq.front()]);
        }

        return ans;
}

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int k;
    cout<<"Enter the size of the window: ";
    cin>>k;
    vector<int> ans=printFirstNegativeInteger(v,n,k);
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
}