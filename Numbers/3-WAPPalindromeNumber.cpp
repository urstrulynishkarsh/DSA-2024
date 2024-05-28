#include<iostream>
#include<limits.h>
using namespace std;

int ReverseNumber(int n)
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

bool PalindromeNumber(int &n)
{
     int reverse=ReverseNumber(n);
    if(n<0)
    {
        return false;
    }
    if(n==reverse)
    {
        return true;
    }
    return false;
}

int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<PalindromeNumber(n);

   
}
