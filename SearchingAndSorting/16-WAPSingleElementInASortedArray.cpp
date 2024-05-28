#include<iostream>
#include<vector>
using namespace std;

int SingleElementInasortedArray(vector<int> &arr)
{
    int s=0;
    int e=arr.size()-1;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
       if(s==e)
       {
        return arr[s];
       }
       if(mid%2==0){
            if(arr[mid]==arr[mid+1])
            {
                s=mid+2;
            }
            else{
                e=mid;
            }
       }
       else{
             if(arr[mid]==arr[mid-1])
            {
                s=mid+1;
            }
            else{
                e=mid-1;
            }
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
   
    cout<<SingleElementInasortedArray(v);
}