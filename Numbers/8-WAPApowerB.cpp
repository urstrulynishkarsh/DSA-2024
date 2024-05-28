#include<iostream>
#include<algorithm>
using namespace std;

// int Power(int a,int b)
// {
//     if(b==0)
//     {
//         return 1;
//     }
//     int ans=1;
//     for(int i=0;i<b;i++)
//     {
//         ans*=a;
//     }
//     return ans;
// }
// O(b);



int fastExponentiation(int a,int b)
{
    int ans=1;
    while(b>0)
    {
        // if b is odd
        if(b&1)
        {
            ans=(ans*a);
        }
        a=a*a;
        b>>=1;
    }
    return ans;
}

int main(){
    int a,b;
    cout<<"Enter the a value: ";
    cin>>a;
    cout<<"Enter the b value: ";
    cin>>b;
    cout<<fastExponentiation(a,b);

}