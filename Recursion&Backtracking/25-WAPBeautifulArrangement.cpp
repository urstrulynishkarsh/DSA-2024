#include<iostream>
#include<vector>
#include<string.h>
#include<string>
#include<unordered_map>
using namespace std;

  void countArrangementHelper(int &n, vector<int> &v,int &ans,int value)
    {   
        if(value==n+1)
        {
            ans++;
            return;
        }
        for(int i=1;i<=n;i++)
        {
            if(v[i]==0 && (value%i==0 ||i%value==0))
            {
                v[i]=value;
                countArrangementHelper(n,v,ans,value+1);
                v[i]=0;
            }
        }
    }

int main()
{
    int n;
    cout<<"Enter the Number: ";
    cin>>n;
     vector<int> v(n+1);
        int ans=0;
        countArrangementHelper(n,v,ans,1);
        cout<<ans;
}