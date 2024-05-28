#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

void nextPermutation(vector<int>& nums) {
     next_permutation(nums.begin(),nums.end());
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
    nextPermutation(v);
    for(auto val:v)
    {
        cout<<val<<" ";
    }
   
    
}