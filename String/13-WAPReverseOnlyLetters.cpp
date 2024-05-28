#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

string ReverseOnlyLetter(string &str)
{
    int s=0;
    int e=str.length()-1;
    while(s<=e)
    {
       if(isalpha(str[s]) && isalpha(str[e]))
       {
            swap(str[s++],str[e--]);
       }
       else if(!isalpha(str[s]))
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

  

    cout<<ReverseOnlyLetter(str);

   




}