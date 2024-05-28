#include<iostream>
#include<cstring>
#include<string.h>
#include<unordered_map>
using namespace std;

char decodeIt(string str, int k)
    {
        
        string newStr;
        for(int i=0;i<str.length();i++)
        {
            if(!isdigit(str[i]))
            {
                newStr+=str[i];
            }
            else
            {
                int m=str[i]-'0';
                string res=newStr;
                for(int i=1;i<=m-1;i++)
                {
                    newStr+=res;
                }
            }
        }
        return newStr[k-1];
        // Write your code here
    }

int main()
{
    string str1;
    cout<<"Enter your first string: ";
    getline(cin,str1);
    cout<<decodeIt(str1,8);

}
