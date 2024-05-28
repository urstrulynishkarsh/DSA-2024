#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int coinChange(vector<int> &v,int target)
{
   if(target==0)
   {
        return 0;
   }
   if(target<0)
   {
    return INT_MAX;
   }
   int mini=INT_MAX;
   for(int i=0;i<v.size();i++)
   {
        int ans=coinChange(v,target-v[i]);
        if(ans!=INT_MAX)
        {
            mini=min(mini,ans+1);
        }
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
    int target;
    cout<<"Enter the amount: ";
    cin>>target;

   int ans=coinChange(v,target);

   if(ans==INT_MAX)
   {
        return -1; 
   }
   cout<<ans;
    
}