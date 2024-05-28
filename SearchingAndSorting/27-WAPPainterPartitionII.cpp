#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool possibleSolution(vector<int> &v,int n,int m,long long solution)
{
    long long timeSum =0;
    long long count=1;
    for(int i=0;i<n;i++)
    {
        if(v[i]>solution)
        {
            return false;
        }
        if(timeSum+v[i]>solution)
        {
            count++;
            timeSum=v[i];
            if(count>m)
            {
                return false;
            }
        }
        else{
            timeSum+=v[i];
        }
    }
    return true;
}


long long PainterPartitionProblem(vector<int> &v,int n,int m)
{
    if(m>n)
    {
        return -1;
    }
    long long s=0;
    long long e;
    for(int i=0;i<n;i++)
    {
        e+=v[i];
    }
    long long ans=-1;
    while(s<=e)
    {
        long long mid=s+((e-s)>>1);
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
    cout<<"Enter the number Painter: ";
    cin>>m;
    cout<<PainterPartitionProblem(v,n,m);
}