#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int BinarySearch(vector<int> &v,int &target,int s,int e)
{
    
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(v[mid]==target)
        {
            return mid;
        }
        else if(v[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return -1;
}

int UnBoundedInFiniteArray(vector<int> &v,int &target)
{

    int i=0;
    int j=1;
        while(v[j]<target)
        {
            i=j;
            j=j*2;
        }
int s=i;
int e=j;
   

    return BinarySearch(v,target,s,e);

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
    cout<<UnBoundedInFiniteArray(v,target);
}