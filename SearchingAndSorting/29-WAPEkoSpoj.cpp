#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool possibleSolution(vector<int> &v,int n,int m,int solution)
{
    int woodcollected=0;
    for(int i=0;i<n;i++)
    {
        if(v[i]>solution)
        {
            woodcollected+=v[i]-solution;
        }
    }
    return woodcollected>=m;
}


int EkoSpoj(vector<int> &v,int n,int m)
{
    // sort(v.begin(),v.end());
    int s=0;
    int e=*max_element(v.begin(),v.end());
    int ans=-1;
    while(s<=e)
    {
        int mid=s+(e-s)/2;
        if(possibleSolution(v,n,m,mid))
        {
            ans=mid;
            s=mid+1;
        }
        else{
            e=mid-1;
        }
    }
    return ans;
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
    int height;
    cout<<"Enter the height : ";
    cin>>height;
    cout<<EkoSpoj(v,n,height);
}