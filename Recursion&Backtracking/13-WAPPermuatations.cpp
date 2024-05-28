#include<iostream>
#include<vector>
using namespace std;

void Permutations(vector<int> &nums, vector<vector<int> > &result,int i)
    {
        if(i>=nums.size())
        {
            result.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            Permutations(nums,result,i+1);
            swap(nums[i],nums[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int> > result;
        int index=0;
        Permutations(nums,result,index);
        return result;
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
   permute(v);

  
    
}