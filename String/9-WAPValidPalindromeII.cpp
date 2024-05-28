#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

bool isPalindrome(string s,int low,int high) {
   
        while(low<=high)
        {
            if(s[low]!=s[high])
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


bool ValidPlaindromeII(string & str)
{
    int i=0;
    int j=str.length()-1;
    while(i<=j)
    {
        if(str[i]!=str[j])
        {
            return isPalindrome(str,i+1,j)|| isPalindrome(str,i,j-1);
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}

int main()
{
    string str;
    cout<<"Enter your string: ";
    getline(cin,str);

    cout<<ValidPlaindromeII(str);






}