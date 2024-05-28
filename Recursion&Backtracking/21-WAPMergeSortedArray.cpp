#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size first of array: ";
    cin>>n;
    vector<int> nums1(n*2);
    cout<<"Enter the element in the first array: ";
    for(int i=0;i<n*2;i++)
    {
        cin>>nums1[i];
    }
     int m;
    cout<<"Enter the size second of array: ";
    cin>>m;
    vector<int> nums2(m);
    cout<<"Enter the element in the second array: ";
    for(int i=0;i<m;i++)
    {
        cin>>nums2[i];
    }
       vector<int> v;
        int i=0;
        int j=0;
        while(i<m && j<n)
        {
            if(nums1[i]<=nums2[j])
            {
                v.push_back(nums1[i++]);
            }
            else
            {
                v.push_back(nums2[j++]);
            }
        }
        while(i<m)
        {
             v.push_back(nums1[i++]);
        }
         while(j<n)
         {
              v.push_back(nums2[j++]);
         }

         for(int i=0;i<v.size();i++)
        {
            nums1[i]=v[i];
        }

        for(int i=0;i<nums1.size();i++)
        {
            cout<<nums1[i]<<" ";
        }


}
