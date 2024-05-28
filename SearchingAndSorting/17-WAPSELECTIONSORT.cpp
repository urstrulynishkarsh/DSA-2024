#include<iostream>
#include<vector>
using namespace std;

void SelectionSort(vector<int> &nums)
{
    for(int i=0;i<nums.size()-1;i++)
    {
        int minindex=i;
        for(int j=i+1;j<nums.size();j++)
        {
            if(nums[j]<nums[minindex])
            {
               minindex=j;
            }
        }
        swap(nums[i],nums[minindex]);
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
   
    SelectionSort(v);

    for(auto val:v)
    {
        cout<<val<<" ";
    }
}