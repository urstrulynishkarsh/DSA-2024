 #include<iostream>
#include<vector>
#include<limits.h>
using namespace std;       
        
        
        
   void TwoSum(vector<int> &nums,vector<int> &ans,int &target){
        for(int i=0;i<nums.size();i++)
        {
            for(int j=i+1;j<nums.size();j++)
            {
                if(nums[i]+nums[j]==target)
                {
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
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
    int target;
    cout<<"Enter the target Value: ";
    cin>>target;
    vector<int> ans;
    TwoSum(v,ans,target);
    for(auto val:ans)
    {
        cout<<val<<" ";
    }
   
    
}