#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

string RemoveAllAdjacent(string &str)
{
    string ans;
    for(int i=0;i<str.length();i++)
    {
        if(ans.length()>0 && ans[ans.length()-1]==str[i])
        {
            ans.pop_back();
        }
        else{
            ans.push_back(str[i]);
        }
    }
    return ans;

}

int main()
{
    string str;
    cout<<"Enter your string: ";
    getline(cin,str);
    cout<<RemoveAllAdjacent(str);
}