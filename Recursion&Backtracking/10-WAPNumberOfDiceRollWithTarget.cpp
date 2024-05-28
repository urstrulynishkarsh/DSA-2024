#include<iostream>
using namespace std;

int DiceRoll(int n, int k,int target)
{
    if(target<0)
    {
        return 0;
    }
    if(target==0 && n==0)
    {
        return 1;
    }
     if(target==0 && n!=0)
    {
        return 0;
    }
     if(target!=0 && n==0)
    {
        return 0;
    }

    int ans=0;
    for(int i=1;i<=k;i++)
    {
        ans=ans+DiceRoll(n-1,k,target-i);
    }
    return ans;

}

int main()
{
     int n,k,target;
     cout<<"Enter the value of n, k, target: ";
     cin>>n>>k>>target;
     cout<<DiceRoll(n,k,target);
}