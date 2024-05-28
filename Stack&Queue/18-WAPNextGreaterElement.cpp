#include<iostream>
#include<vector>
#include<limits.h>
#include<stack>
using namespace std;

 vector<int> nextLargerElement(vector<int> arr, int n){
        // Your code here
        vector<int> ans(n, -1);
        stack<int> st;
      for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[i] > arr[st.top()]) {
            int top = st.top();
            st.pop();
            ans[top] = arr[i];
        }
        st.push(i);
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
   vector<int> ans=nextLargerElement(v,n);
   for(auto val:ans)
   {
    cout<<val<<" ";
   }
}