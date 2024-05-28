#include<iostream>
using namespace std;

int SquareRoot(int &n)
{
    int s=0;
    int e=n;
    int mid=s+(e-s)/2;
    int ans=-1;
    while(s<=e)
    {
         if(mid*mid==n)
        {
            return mid;
        }
        if(mid*mid>n)
        {
            e=mid-1;
        }
       
        else{
            ans=mid;
            s=mid+1;
        }
        mid=s+(e-s)/2;
    }
    return ans;


}

int main()
{
    int number;
    cout<<"Enter the number: ";
    cin>>number;
    int ans=SquareRoot(number);
    cout<<ans<<endl;
    int precision;
    cout<<"Enter the Floating digit you want: ";
    cin>>precision;

    double step=0.1;
    double FinalAns=ans;

    for(int i=0;i<precision;i++)
    {
        for(double j=FinalAns;j*j<=number;j=j+step)
        {
            FinalAns=j;
        }
        step=step/10;
    }
    cout<<"Square root of "<<number<<" is: "<<FinalAns;
}