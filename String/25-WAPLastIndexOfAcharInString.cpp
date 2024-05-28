#include<iostream>
#include<string>
#include<string.h>
using namespace std;

int LastIndex(string str, char ch )
{
    int j=str.length()-1;
    while(j>=0)
    {
        if(str[j]==ch)
        {
            return j;
        }
    }
    return 0;
}

int main(){
    string str;
    cout<<"Enter the string: ";
    getline(cin,str);
    char ch;
    cout<<"Enter the search character: ";
    cin>>ch;
    cout<<LastIndex(str,ch);
}