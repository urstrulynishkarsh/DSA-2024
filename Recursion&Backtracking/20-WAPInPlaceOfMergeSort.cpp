#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;


  void Merge(vector<int>& nums,vector<int> &temp,int mid,int s, int e)
    {
        int i=s;
        int j=mid+1;
        int k=s;
        while(i<=mid && j<=e)
        {
            if(nums[i]<=nums[j])
            {
                temp[k++]=nums[i++];
            }
            else
            {
                temp[k++]=nums[j++];
            }
        }
        while(i<=mid)
        {
            temp[k++]=nums[i++];
        }
        while(j<=e)
        {
             temp[k++]=nums[j++];
        }

        while(s<=e)
        {
            nums[s]=temp[s];
            s++;
        }
    }

    void MergeSort(vector<int>& nums,vector<int> &temp,int s, int e)
    {
        if(s>=e)
        {
            return;
        }
        int mid=s+(e-s)/2;
        MergeSort(nums,temp,s,mid);
        MergeSort(nums,temp,mid+1,e);
        Merge(nums,temp,mid,s,e);
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
    vector<int> temp(v.size(),0);
    int s=0;
    int e=n-1;
      MergeSort(v,temp,s,e);
      for(auto val:v)
      {
        cout<<val<<" ";
      }


}

