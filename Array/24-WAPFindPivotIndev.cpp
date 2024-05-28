 #include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;       
        
        
        
int FindPivotIndex(vector<int> &nums){
    int rightSum=0;
    int leftSum=0;
    for(auto val:nums)
    {
        rightSum+=val;
    }
    for(int i=0;i<nums.size();i++)
    {
        rightSum-=nums[i];
        if(leftSum==rightSum)
        {
            return i;
        }
        leftSum+=nums[i];
    }
    return -1;

      
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
 
    cout<<FindPivotIndex(v);
   
   
    
}