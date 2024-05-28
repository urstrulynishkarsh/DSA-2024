#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;



int maxSubArray(vector<int>& nums) {
        int sum=0;
        int maxi=nums[0];
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
            maxi=max(maxi,sum);
            if(sum<0)
            {
                sum=0;
            }
        }
        return maxi;
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
    cout<<maxSubArray(v);
   
    
}