#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

bool isPalindrome(string s) {
        int low=0;
        int high=s.length()-1;
        while(low<=high)
        {
            if(!isalnum(s[low]))
            {
                low++;
                continue;
            }
            if(!isalnum(s[high]))
            {
                high--;
                continue;
            }
            if(tolower(s[low])!=tolower(s[high]))
            {
                return false;
            }
            else
            {
                low++;
                high--;
            }
        }
        return true;
    }

int main()
{
    string str;
    cout<<"Enter your string: ";
    getline(cin,str);

    cout<<isPalindrome(str);






}