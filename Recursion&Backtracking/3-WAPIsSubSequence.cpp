#include<iostream>
#include<string.h>
#include<string>
using namespace std;

bool isSubSequence(string s,string t)
{
    int count=0;
    for(int i=0;i<t.size();i++)
    {
        if(s[count]==t[i])
        {
            count++;
        }
    }
    if(s.length()==count)
    {
        return true;
    }
    return false;
}
int main()
{
    string s;
    cout<<"Enter the first string: ";
    getline(cin,s);
    string t;
    cout<<"Enter the second string: ";
    getline(cin,t);

    cout<<isSubSequence(s,t);

}