#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

string RemoveAllOccurenceOfSubstring(string &str, string &part)
{
    int pos=str.find(part);
    while(pos!=string::npos)
    {
        str.erase(pos,part.length());
        pos=str.find(part);
    }
    return str;

}

int main()
{
    string str;
    cout<<"Enter your string: ";
    getline(cin,str);
    string part;
    cout<<"Enter the substring: ";
    getline(cin,part);
    cout<<RemoveAllOccurenceOfSubstring(str,part);
}