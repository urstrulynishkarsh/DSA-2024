#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

void ReverseString(string &str)
{
    int s=0;
    int e=str.length()-1;
    while(s<=e)
    {
        swap(str[s++],str[e--]);
    }
}

int main()
{
    string str;
    cout<<"Enter your string: ";
    getline(cin,str);

    cout<<str<<endl;

    ReverseString(str);

    cout<<str;




}