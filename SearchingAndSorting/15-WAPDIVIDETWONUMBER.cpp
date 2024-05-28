#include<iostream>
#include<vector>
using namespace std;

int DivideTwoNumber(int &dividend,int &divisor)
{
if(dividend==INT_MIN && divisor==-1)
        {
            return INT_MAX;
        }
        long long int ans=dividend/divisor;
        if(ans>INT_MAX)
        {
             return INT_MAX;
        }
        if(ans<INT_MIN)
        {
             return INT_MIN;
        }
        return ans;
}

int main(){
    int dividend;
    cout<<"Enter the dividend: ";
    cin>>dividend;
    int divisor;
    cout<<"Enter the Divisor: ";
    cin>>divisor;

   cout<<DivideTwoNumber(dividend,divisor);


}