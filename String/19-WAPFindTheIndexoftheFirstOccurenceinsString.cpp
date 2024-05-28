#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;


int strStr(string haystack, string needle) {
        return haystack.find(needle);
}


int main()
{
    string str1;
    cout<<"Enter your first string: ";
    getline(cin,str1);
    string str2;
    cout<<"Enter your second string: ";
    getline(cin,str2);

    cout<<strStr(str1,str2);

}