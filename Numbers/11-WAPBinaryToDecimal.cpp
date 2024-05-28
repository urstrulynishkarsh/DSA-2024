#include<iostream>
using namespace std;

int BinaryToDecimal(int &n)
{
    int decimalNo=0;
    int i=0;
    while(n)
    {
        int bit=n%10;
        decimalNo=bit*pow(2,i++)+decimalNo;
        n/=10;
    }
    return decimalNo;
}

int main(){
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    cout<<BinaryToDecimal(n); 
}