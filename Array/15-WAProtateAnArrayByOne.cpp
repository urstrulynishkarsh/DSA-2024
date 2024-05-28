#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void RotateAnArrayByOne(vector<int>& v) {
    int temp;
    for(int i=0;i<v.size();i++)
    {
        temp=v[i];
        v[i]=v[v.size()-1];
        v[v.size()-1]=temp;
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
    RotateAnArrayByOne(v);

   for(auto ele:v)
   {
    cout<<ele<<" ";
   }
    
}