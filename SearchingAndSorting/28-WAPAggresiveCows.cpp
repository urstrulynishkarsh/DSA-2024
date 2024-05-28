#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool possibleSolution(vector<int> &v,int n,int m,int solution)
{
    int count=1;
    int position=v[0];
    for(int i=1;i<n;i++)
    {
        if(v[i]-position>=solution)
        {
            count++;
            position=v[i];
        }
        if(count==m)
        {
            return true;
        }
    }
    return false;
}


int AggresiveCows(vector<int> &v,int n,int m)
{
    sort(v.begin(),v.end());
    int s=0;
    int e=(v[n-1]-v[0]);
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
    int m;
    cout<<"Enter the number Painter: ";
    cin>>m;
    cout<<AggresiveCows(v,n,m);
}