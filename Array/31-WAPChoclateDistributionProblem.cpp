#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;




   int ChoclateDistribution(vector<int>& num,int n, int m) {
       sort(num.begin(),num.end());
       int mini=INT_MAX;
       for(int i=0;i<=n-m;i++)
       {
            int diff=num[m-1+i]-num[i];
            mini=min(mini,diff);
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
    int m;
    cout<<"Enter the Student: ";
    cin>>m;

    cout<<ChoclateDistribution(v,n,m);
   
   
    
}