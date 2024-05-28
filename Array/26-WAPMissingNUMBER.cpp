#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;




   int MissingNumber(vector<int>& nums) {
       int n=nums.size();
        int totalsum=(n*(n+1))/2;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            sum+=nums[i];
        }
        return totalsum-sum;
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
    cout<<MissingNumber(v);
   
    
}