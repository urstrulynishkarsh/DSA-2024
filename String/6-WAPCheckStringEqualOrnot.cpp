#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

bool CompareBothString(string &str1, string &str2)
{
    if(str1.length()!=str2.length())
    {
        return false;
    }
    for(int i=0;i<str1.length();i++)
    {
        if(str1[i]!=str2[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    string str1;
    cout<<"Enter your first string: ";
    getline(cin,str1);
    string str2;
    cout<<"Enter your second string: ";
    getline(cin,str2);

    cout<<CompareBothString(str1,str2);

}