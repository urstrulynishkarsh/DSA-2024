#include<iostream>
#include<vector>
#include<string.h>
#include<string>
using namespace std;

string ZigZagConversion(string &s,int &numRow)
{
    if(numRow==1)
    {
        return s;
    }
    vector<string> zingzag(numRow);
    int i=0;
    int row=0;
    bool direction=1;
    while(true)
    {
        if(direction)
        {
            while(row<numRow && i<s.length())
            {
                zingzag[row++].push_back(s[i++]);
            }
            row=numRow-2;
        }
        else{
            while(row>=0 && i<s.length())
            {
                zingzag[row--].push_back(s[i++]);
            }
            row=1;
        }
        if(i>=s.length())
        {
            break;
        }
        direction=!direction;
    }
    string ans;
    for(int i=0;i<zingzag.size();i++)
    {
        ans+=zingzag[i];
    }
    return ans;
}
int main()
{
     string str;
    cout<<"Enter your string: ";
    getline(cin,str);

    int numRow;
    cout<<"Enter the NumRow: ";
    cin>>numRow;

  

    cout<<ZigZagConversion(str,numRow);
}