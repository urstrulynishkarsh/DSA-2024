#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int FindUniqueElement(vector<int> &v)
{
    int ans=0;
    for(int i=0;i<v.size();i++)
    {
        ans^=v[i];
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
   cout<<FindUniqueElement(v);
    
}