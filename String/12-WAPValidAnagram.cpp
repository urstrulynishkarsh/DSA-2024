#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

bool validAnagram(string &str1, string &str2)
{
    int hash[256]={0};
    for(int i=0;i<str1.length();i++)
    {
        hash[str1[i]]++;
    }
     for(int i=0;i<str2.length();i++)
    {
        hash[str2[i]]--;
    }
    for(int i=0;i<256;i++)
    {
        if(hash[i]!=0)
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

    cout<<validAnagram(str1,str2);

}