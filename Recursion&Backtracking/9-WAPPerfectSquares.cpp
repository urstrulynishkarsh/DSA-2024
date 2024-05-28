#include<iostream>
#include<limits.h>
using namespace std;

int  PerfectSquare(int n)
{
    if(n==0)
    {
        return 0;
    }
    int ans=INT_MAX;
    for(int i=1;i*i<=n;i++)
    {
        ans=min(ans,PerfectSquare(n-i*i)+1);
    }
    return ans;
}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<PerfectSquare(n);
}