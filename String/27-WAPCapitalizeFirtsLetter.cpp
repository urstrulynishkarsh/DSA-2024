#include<iostream>
#include<string.h>
using namespace std;

void Conversion(string &str, string &result)
{
    bool capitalizeNext=true;
    for(int i=0;i<result.length();i++)
    if(isspace(result[i]))
    {
        capitalizeNext = true;
    }
    else if(capitalizeNext)
    {
        result[i]=toupper(result[i]);
        capitalizeNext=false;
    }
    else{
        result[i]=tolower(result[i]);
    }
}
int main(){
    string str;
    cout<<"Enter the string: ";
   getline(cin,str);
    string result=str;
    Conversion(str,result);
    cout<<result;
}