#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


bool isPossible(vector<int> &v, int n, int k,int requiredSum)
{
    int count=1;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        if(sum+v[i]<=requiredSum)
        {
            sum+=v[i];
        }
        else{
             sum=v[i];
             count++;
        }
    }
    return count<=k;
}


int SplitArrayLargestSum(vector<int> &v, int n, int k)
{
    int totalsum=0;
    int maxi=INT_MIN;
    for(int i=0;i<n;i++)
    {
        totalsum+=v[i];
        maxi=max(maxi,v[i]);
    }
    int s=maxi;
    int e=totalsum;
    int ans=INT_MAX;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(isPossible(v,n,k,mid))
        {
            ans=mid;
            e=mid-1;
        }
        else{
            s=mid+1;
        }
    }
    return ans;
}

int main(){
    int n;
    cout<<"Enter the size of Array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the value in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    int k;
    cout<<"Enter the value you want to sum split: ";
    cin>>k;

    cout<<SplitArrayLargestSum(v,n,k);

}