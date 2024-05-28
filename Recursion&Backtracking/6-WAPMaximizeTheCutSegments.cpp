#include<iostream>
using namespace std;

int CutIntoSegment(int n,int x,int y,int z)
{
    if(n==0)
    {
        return 0;
    }
    if(n<0)
    {
        return -1;
    }
    int ans=max(CutIntoSegment(n-x,x,y,z),max(CutIntoSegment(n-y,x,y,z),CutIntoSegment(n-z,x,y,z)));
    if(ans==-1)
    {
        return -1;
    }
    return ans+1;
}

int main()
{
    int n,x,y,z;
    cout<<"Enter the value of n, x, y, z: ";
    cin>>n>>x>>y>>z;
    cout<<CutIntoSegment(n,x,y,z);
}