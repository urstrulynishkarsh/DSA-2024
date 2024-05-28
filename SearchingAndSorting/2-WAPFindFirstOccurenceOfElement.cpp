#include<iostream>
#include<vector>
using namespace std;

int FirstOccurrenceOfElement(vector<int> &v,int &target)
{
    int s=0;
    int e=v.size()-1;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e)
    {
        if(v[mid]==target)
        {
            ans=mid;
            e=mid-1;
        }
        else if(v[mid]>target){
            e=mid-1;
        }
        else{
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;;
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
    cout<<FirstOccurrenceOfElement(v,target);
}