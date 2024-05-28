#include<iostream>
#include<cstring>
#include<string.h>
#include<unordered_map>
using namespace std;

bool IsomorphicString(string &str1, string &str2)
{
    unordered_map<char,char> map1,map2;
    for(int i=0;i<str1.length();i++)
    {
        if(map1[str1[i]] &&  map1[str1[i]]!=str2[i])
        {
            return false;
        }
         if(map2[str2[i]] &&  map2[str2[i]]!=str1[i])
        {
            return false;
        }

        map1[str1[i]]=str2[i];
        map2[str2[i]]=str1[i];
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

    cout<<IsomorphicString(str1,str2);

}