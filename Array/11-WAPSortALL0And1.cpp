#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void SortAllZeroOne(vector<int> &v)
{
    int l=0;
    int m=0;
    int h=v.size()-1;
    while(m!=h)
    {
        if(v[m]==0)
        {
            swap(v[l],v[m]);
            m++;
            l++;
        }
        if(v[m]==1)
        {
            swap(v[m],v[h]);
            h--;
        }
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
    SortAllZeroOne(v);
    for(auto ele:v)
    {
        cout<<ele<<" ";
    }
    
}