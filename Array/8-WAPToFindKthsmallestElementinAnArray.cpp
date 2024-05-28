#include<iostream>
#include<vector>
#include<limits.h>
#include<queue>
using namespace std;

static bool mycmp(int &a,int &b)
{
    return a<b;
}

int KthSmallestElement(vector<int> &v,int &k)
{
    // sort(v.begin(),v.end(),mycmp);
    // return v[k-1];

      priority_queue<int> pq;
    for(auto num:v)
    {
        pq.push(num);
        if(pq.size()>k)
        {
            pq.pop();
        }
    }
    return pq.top();
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
    cout<<"Enter the Kth largest element: ";
    cin>>k;
   cout<<KthSmallestElement(v,k);
    
}