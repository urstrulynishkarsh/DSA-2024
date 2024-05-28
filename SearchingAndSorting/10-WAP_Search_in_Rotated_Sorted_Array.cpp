#include<iostream>
#include<vector>
using namespace std;


int binarySearch(vector<int> nums, int target,int s,int e)
{
    // int s = 0;
    // int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    int ans = -1;
    while (s <= e)
    {
        if (target == nums[mid])
        {
            return mid;
        }
        else if (target > nums[mid])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}
int pivotElement(vector<int> &nums)
{
    int s = 0;
    int e = nums.size() - 1;
    int mid = s + (e - s) / 2;
    while (s < e)
    {
        if (nums[mid] > nums[mid + 1] && mid + 1 < nums.size())
        {
            return mid;
        }
        if (mid - 1 >= 0 && nums[mid - 1] > nums[mid]  )
        {
            return mid - 1;
        }
        if (nums[s] >= nums[mid])
        {
            e = mid - 1;
        }
        else
        {
            s = mid;
        }
        mid = s + (e - s) / 2;
    }
    return s;
}
    int search(vector<int>& nums, int target) {
        
        int pivot=pivotElement(nums);
        if(target>=nums[0] && target<=nums[pivot])
        {
            int ans=binarySearch(nums,target,0,pivot);
            return ans;
        }
        // if(pivot+1<nums.size() && target>=nums[pivot+1] && target<=nums[nums.size()-1])
        else
        {
            int ans=binarySearch(nums,target,pivot+1,nums.size()-1);
            return ans;
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
    int target;
    cout<<"Enter the seach element: ";
    cin>>target;
    cout<<search(v,target);
}