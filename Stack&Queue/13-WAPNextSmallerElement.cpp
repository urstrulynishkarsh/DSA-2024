#include<iostream>
#include<vector>
#include<stack>
using namespace std;


void NextSmallerElement(vector<int> &v, int &n,vector<int> &ans)
{
    stack<int> st;
    st.push(-1);
    for(int i=n-1;i>=0;i--)
    {
        int curr=v[i];
        while(st.top()>=curr)
        {
            st.pop();
        }
        ans[i]=st.top();
        st.push(curr);
    }
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
    vector<int> ans(n);
    NextSmallerElement(v,n,ans);

    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
}