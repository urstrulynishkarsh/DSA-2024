#include<iostream>
#include<algorithm>
using namespace std;

int gcd( int small, int large ){
   
    if(small==0)
    {
        return large;
    }
    if(large==0)
    {
        return small;
    }
    while(small>0 && large>0)
    {
        if(small>large)
        {
            small-=large;
        }
        else{
            large-=small;
        }
    }
    return small==0?large:small;
}


int NthMagicalNumber(int n, int a,int b)
{
    long long int lcm=a*b/gcd(a,b);
    long long int s=min(a,b);
    long long int e=n*s;
    long long int mid,c;
    while(s<e)
    {
        mid=s+(e-s)/2;
        c=mid/a+mid/b-mid/lcm;
        if(c<n)
        {
            s=mid+1;
        }
        else{
            e=mid;
        }
    }
    int mod=1e9+7;
    return e%mod;
}

int main(){
    int n,a,b;
    cout<<"Enter the n value: ";
    cin>>n;
    cout<<"Enter the a value: ";
    cin>>a;
    cout<<"Enter the b value: ";
    cin>>b;

    cout<<NthMagicalNumber(n,a,b);


}