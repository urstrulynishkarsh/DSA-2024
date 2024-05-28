#include<iostream>
#include<limits.h>
using namespace std;

int ReverseNumber(int &n)
{
    int reversed=0;
    while(n!=0)
    {
        int digit=n%10;
        if(reversed>INT_MAX/10 || reversed<INT_MIN/10)
        {
            return 0;
        }
        reversed=reversed*10+digit;
       
        n/=10;
    }
    return reversed;
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;

    cout<<ReverseNumber(n);
}
