#include<iostream>
#include<algorithm>
using namespace std;

double Power(double x,int n)
{
    if(n<0)
    {
        x=1/x;
    }
    long num=labs(n);
    double power=1;
    while(num!=0)
    {
        if(num&1)
        {
            power*=x;
        }
        x*=x;
        num>>=1;
    }
    return power;
}

int main(){
    double x;
    cout<<"Enter the value of n: ";
    cin>>x;
    int n;
    cout<<"Enter the value of x: ";
    cin>>n;
    cout<<Power(x,n);
}