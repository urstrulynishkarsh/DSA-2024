#include<iostream>
#include<vector>
using namespace std;

int PeakElement(vector<int> &v)
{
    int s=0;
    int e=v.size()-1;
    int mid=s+(e-s)/2;
    while(s<e)
    {
        if(v[mid]<v[mid+1])
        {
            s=mid+1;
        }
        else{
            e=mid;
        }
        mid=s+(e-s)/2;
    }
    return e;
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
    cout<<PeakElement(v);
}