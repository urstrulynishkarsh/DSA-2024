#include<iostream>
#include<cstring>
#include<string.h>
#include<limits.h>
#include<vector>
using namespace std;

static bool mycmp(string &a, string &b)
{
    return a+b>b+a;
}

string LargestNumber(vector<int> &v)
{
    vector<string> stringNumber;
    for(auto val:v)
    {
        stringNumber.push_back(to_string(val));
    }
    sort(stringNumber.begin(),stringNumber.end(),mycmp);
    if(stringNumber[0]=="0")
    {
        return "0";
    }
    string ans;
    for(int i=0;i<stringNumber.size();i++)
    {
        ans+=stringNumber[i];
    }
    return ans;


}

int main(){
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<LargestNumber(v);
}