#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

int LengthOfString(string &str)
{
   int i=0;
   int count=0;
   while(str[i]!='\0')
   {
        i++;
   }
   return i;
}

int main()
{
    string str;
    cout<<"Enter your string: ";
    getline(cin,str);
    cout<<LengthOfString(str);
}