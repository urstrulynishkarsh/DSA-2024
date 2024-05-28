#include<iostream>
using namespace std;


int DecimalToBinary(int n)
{
    int binaryno=0;
    int i=0;
    while(n!=0)
    {
        // int bit=n%2;
        // binaryno=bit*pow(10,i++)+binaryno;
        // n/=2;
        int bit=n&1;
        binaryno=bit*pow(10,i++)+binaryno;
        n>>=1;   

    }
    return binaryno;

}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<DecimalToBinary(n);    
     
}