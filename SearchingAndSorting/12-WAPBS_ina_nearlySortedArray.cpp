#include<iostream>
#include<vector>
using namespace std;

int BinarySearchInaNearlySortedArray(vector<int> &v,int &target)
{
    int s=0;
    int e=v.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
       if(v[mid]==target)
       {
            return mid;
       }
       if(mid-1>=0 && v[mid-1]==target)
       {
        return mid-1;
       }
       if( mid+1<v.size() &&v[mid+1]==target)
       {
        return mid+1;
       }
       if(v[mid]<target)
       {
        s=mid+2;
       
       }
       if(v[mid]>target)
       {
         e=mid-2;
       }

        mid=s+(e-s)/2;
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
    cout<<BinarySearchInaNearlySortedArray(v,target);
}