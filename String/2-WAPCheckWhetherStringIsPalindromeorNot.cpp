#include<iostream>
#include<cstring>
#include<string.h>
using namespace std;

int ReverseString(string &S)
{
     	int s=0;
	    int e=S.length()-1;
	    while(s<=e)
	    {
	        if(S[s]!=S[e])
	        {
	            return false;
	        }
	        else{
	            s++;
	            e--;
	        }
	    }
	    return true;
}

int main()
{
    string str;
    cout<<"Enter your string: ";
    getline(cin,str);

    cout<<ReverseString(str);






}