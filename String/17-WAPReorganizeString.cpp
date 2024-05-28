#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

string ReOrganize(string &str)
{   
    int hash[26]={0};
    for(int i=0;i<str.length();i++)
    {
        hash[str[i]-'a']++;
    }
    char mostOccurrcenceChar;
    int maxFreq=INT_MIN;
    for(int i=0;i<26;i++)
    {
        if(hash[i]>maxFreq)
        {
            maxFreq=hash[i];
            mostOccurrcenceChar=i+'a';
        }
    }
    int index=0;
    while(maxFreq>0 && index<str.length())
    {
        str[index]=mostOccurrcenceChar;
        maxFreq--;
        index+=2;
    }
    if(maxFreq!=0)
    {
        return "";
    }
    hash[mostOccurrcenceChar-'a']=0;

    for(int i=0;i<26;i++)
    {
        while(hash[i]>0)
        {
            index=index>=str.length()?1:index;
            str[index]=i+'a';
            hash[i]--;
            index+=2;
        }
    }
    return str;

}

int main()
{
    string str;
    cout<<"Enter your string: ";
    getline(cin,str);
    cout<<ReOrganize(str);

   




}