#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void countAllZeroAndOne(vector<int> &v)
{
    int zero=0;
    int one=0;
    for(int i=0;i<v.size();i++)
    {
        if(v[i]==0)
        {
            zero++;
        }
        if(v[i]==1)
        {
            one++;
        }
    }
    cout<<"Zero is: "<<zero;
    cout<<endl;
    cout<<"One is: "<<one;
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
   countAllZeroAndOne(v);
    
}