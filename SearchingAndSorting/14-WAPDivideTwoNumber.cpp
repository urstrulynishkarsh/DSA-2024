#include<iostream>
#include<vector>
using namespace std;


int DivideTwoNumber(int &dividend,int &divisor)
{
    int s=0;
    int e=abs(dividend);
    int ans=0;
    int mid=s+(e-s)/2;
    while(s<=e)
    {
        if(abs(divisor*mid)==abs(dividend))
        {
            return mid;
        }
        if(abs(divisor*mid)>abs(dividend))
        {
            e=mid-1;
        }
       else
        {
            ans=mid;
            s=mid+1;
        }

        mid=s+(e-s)/2;
    }
   if((dividend<0 && divisor<0) || (dividend>0 && divisor>0))
   {
    return ans;
   }
   else{
    return -ans;
   }
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