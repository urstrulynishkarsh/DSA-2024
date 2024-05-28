#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void  PrintExtremeArray(vector<int> &v)
{
    int s=0;
    int e=v.size()-1;
    while(s<=e)
    {
        if(s>=e)
        {
             cout<<v[e]<<" ";
             break;
        }
        cout<<v[s++]<<" ";
        cout<<v[e--]<<" ";
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
   PrintExtremeArray(v);
    
}