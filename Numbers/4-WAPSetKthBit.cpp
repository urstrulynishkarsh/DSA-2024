#include<iostream>
#include<limits.h>
using namespace std;

int setKthBit(int &n,int k)
{
    int mask=(1<<k);
    return n|mask;
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    int k;
    cout<<"which bit you want to set";
    cin>>k;

    cout<<setKthBit(n,k);
}
