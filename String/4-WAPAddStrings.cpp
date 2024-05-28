#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

void AddString(string str1,string str2,string &ans) {
        int i=str1.size()-1;
        int j=str2.size()-1;
        int carry=0;
        while(i>=0 ||j>=0 ||carry)
        {
            if(i>=0)
            {
                carry+=str1[i--]-'0';  //string to integer we need to minus 0
            }
            if(j>=0)
            {
                carry+=str2[j--]-'0';
            }
            ans+=carry%10+'0';
            carry/=10;
        }
        reverse(ans.begin(),ans.end());
}

int main()
{
    string str1;
    cout<<"Enter your first number string: ";
    getline(cin,str1);
      string str2;
    cout<<"Enter your second number string: ";
    getline(cin,str2);

    string ans;
    AddString(str1,str2,ans);
    cout<<ans;






}