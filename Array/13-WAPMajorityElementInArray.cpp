#include<iostream>
#include<vector>
#include<limits.h>
#include<unordered_map>
using namespace std;

int MajorityElement(vector<int> &nums)
{
    unordered_map<int,int> hash;
        for(int i=0;i<nums.size();i++)
        {
            hash[nums[i]]++;
            if(hash[nums[i]]>nums.size()/2)
            {
                return nums[i];
            }
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
    cout<<MajorityElement(v);
   
    
}