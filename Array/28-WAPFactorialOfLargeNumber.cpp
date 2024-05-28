#include<iostream>
#include<vector>
using namespace std;

void FactorialOfLargeNumber(int n,vector<int> &ans)
{
    ans.push_back(1);
    int carry=0;
    for(int i=2;i<=n;i++)
    {
        for(int j=0;j<ans.size();j++)
        {
            int sum=ans[j]*i+carry;
            ans[j]=sum%10;
            carry=sum/10;
        }
        while(carry)
        {
            ans.push_back(carry%10);
            carry/=10;
        }
    }
    reverse(ans.begin(),ans.end());

}
int main()
{
    int n;
    cout<<"Enter the number: ";
    cin>>n;
    vector<int> ans;
    
    FactorialOfLargeNumber(n,ans);
    for(auto val:ans)
    {
        cout<<val;
    }
}