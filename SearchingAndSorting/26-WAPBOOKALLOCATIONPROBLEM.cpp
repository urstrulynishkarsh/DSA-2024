#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool possibleSolution(vector<int> &v,int n,int m,int solution)
{
    int pageSum=0;
    int count=1;
    for(int i=0;i<n;i++)
    {
        if(v[i]>solution)
        {
            return false;
        }
        if(pageSum+v[i]>solution)
        {
            count++;
            pageSum=v[i];
            if(count>m)
            {
                return false;
            }
        }
        else{
            pageSum+=v[i];
        }
    }
    return true;
}


int BookAllocationProblem(vector<int> &v,int n,int m)
{
    if(m>n)
    {
        return -1;
    }
    int s=0;
    int e;
    for(int i=0;i<n;i++)
    {
        e+=v[i];
    }
    int ans=-1;
    while(s<=e)
    {
        int mid=s+((e-s)>>1);
        if(possibleSolution(v,n,m,mid))
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
    int m;
    cout<<"Enter the number of Student: ";
    cin>>m;
    cout<<BookAllocationProblem(v,n,m);
}