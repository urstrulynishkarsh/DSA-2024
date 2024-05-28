#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int maximumElement(vector<int> &v)
{
    int maxi=INT_MIN;
    for(int i=0;i<v.size();i++)
    {
        maxi=max(v[i],maxi);
    }
    return maxi;
}
int minimumElement(vector<int> &v)
{
    int mini=INT_MAX;
    for(int i=0;i<v.size();i++)
    {
        mini=min(mini,v[i]);
    }
    return mini;
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
    cout<<"Maximum Element is: "<<maximumElement(v)<<endl;
      cout<<"Minimum Element is: "<<minimumElement(v);
}