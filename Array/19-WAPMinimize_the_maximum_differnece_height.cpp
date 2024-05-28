#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;



int maximizeDifferenceHeight(vector<int>& v,int &k) {
    sort(v.begin(),v.end());
    int ans=v[v.size()-1]-v[0];
    int mini=v[0];
    int maxi=v[v.size()-1];
    for(int i=1;i<v.size();i++)
    {
        if(v[i]-k<0)
        {
            continue;
        }
        mini=min(v[0]+k,v[i]-k);
        maxi=max(v[i-1]+k,v[v.size()-1]-k);
        ans=min(ans,maxi-mini);
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
    int height;
    cout<<"Enter height of Tower: ";
    cin>>height;
    cout<<maximizeDifferenceHeight(v,height);
   
    
}