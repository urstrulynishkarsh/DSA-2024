#include<iostream>
#include<vector>
#include<string>
#include<string.h>
using namespace std;

void solution(vector<string> &ans,string output,int index,vector<string> &mapping,string &digit)
{
    if(index>=digit.length())
    {
        ans.push_back(output);
        return;
    }
    int digits=digit[index]-'0';
    string value=mapping[digits];
    for(int i=0;i<value.length();i++)
    {
        char ch=value[i];
        solution(ans,output+ch,index+1,mapping,digit);
    }
}

int main(){
    string digit;
    cout<<"Enter the digit string: ";
    getline(cin,digit);
    vector<string> ans;
    string output;
    int index=0;
    vector<string> mapping(10);
     mapping[2]="abc";
     mapping[3]="def";
        mapping[4]="ghi";
        mapping[5]="jkl";
        mapping[6]="mno";
        mapping[7]="pqrs";
        mapping[8]="tuv";
        mapping[9]="wxyz";
    if(digit.length()==0)
    {
        return ans.size();
    }

    solution(ans,output,index,mapping,digit);

    for(auto val:ans)
    {
        cout<<val<<" ";
    }

}