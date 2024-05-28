#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void SortAllZeroOneTWO(vector<int> &v)
{
    int s=0;
    int m=0;
    int e=v.size()-1;
    while(m<=e)
    {
        if(v[m]==0)
        {
            swap(v[s],v[m]);
            s++;
            m++;
        }
        else if(v[m]==1)
        {
            m++;
        }
        else{
            swap(v[e],v[m]);
            e--;
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
    SortAllZeroOneTWO(v);
    for(auto ele:v)
    {
        cout<<ele<<" ";
    }
    
}