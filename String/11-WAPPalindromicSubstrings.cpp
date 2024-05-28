#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

int CountPlaindrome(string s,int low,int high) {
   int count=0;
   while(low>=0 && high<s.length() && s[low]==s[high])
   {
    count++;
    low--;
    high++;
   }
   return count;
       
}

int PalindromicSubstring(string & str)
{
    int count=0;
    for(int i=0;i<str.length();i++)
    {
        int odd=CountPlaindrome(str,i,i);
        count+=odd;

         int even=CountPlaindrome(str,i,i+1);
         count+=even;
    }
    return count;
}

int main()
{
    string str;
    cout<<"Enter your string: ";
    getline(cin,str);

    cout<<PalindromicSubstring(str);






}