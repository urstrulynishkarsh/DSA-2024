#include<iostream>
#include<cstring>
#include<string.h>
#include<vector>
#include<limits.h>
#include<algorithm>
using namespace std;

int MinimumTimeDifference(vector<string> &v1,int n)
{
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        string current=v1[i];
        int hr=stoi(current.substr(0,2));
        int min=stoi(current.substr(3,2));
        int total=(hr*60)+min;
        ans.push_back(total);
    }
    sort(ans.begin(),ans.end());

    int mini=INT_MAX;
    for(int i=0;i<n-1;i++)
    {
        int diff=ans[i+1]-ans[i];
        mini=min(mini,diff);
    }
    int lastdiff=(ans[0]+1440)-ans[n-1];
    mini=min(mini,lastdiff);

    return mini;

}

int main()
{
     int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<string> v1(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        string input;
        cin >> input;
        v1.push_back(input);
    }
    cout<<MinimumTimeDifference(v1,n);

}