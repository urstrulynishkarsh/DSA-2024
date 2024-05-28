#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;


bool isVowel(char ch)
{
    ch=towlower(ch);
    return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
}

string ReverseOnlyVowels(string &str)
{
    int s=0;
    int e=str.length()-1;
    while(s<=e)
    {
       if(isVowel(str[s]) && isVowel(str[e]))
       {
            swap(str[s++],str[e--]);
       }
       else if(!isVowel(str[s]))
       {
            s++;
       }
       else{
        e--;
       }
    }
    return str;
}

int main()
{
    string str;
    cout<<"Enter your string: ";
    getline(cin,str);

  

    cout<<ReverseOnlyVowels(str);

   




}