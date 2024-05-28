#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;



int DuplicateNumber(vector<int>& nums) {
    while(nums[0]!=nums[nums[0]])
    {
        swap(nums[0],nums[nums[0]]);
    }
    return nums[0];
   
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
    cout<<DuplicateNumber(v);
   
    
}