#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

string AddTwoNumber(vector<int> &a,int n,vector<int> &b,int m){
    // Complete the function
        string ans;
        int carry=0;
        int i=n-1;
        int j=m-1;
        while(i>=0 && j>=0)
        {
            int result=a[i]+b[j]+carry;
                      int digit=result%10;
            ans.push_back(digit+'0');
            carry=result/10;
            i--;
            j--;
        }
        while(i>=0)
        {
             int result=a[i]+0+carry;
                      int digit=result%10;
            ans.push_back(digit+'0');
            carry=result/10;
            i--;
        }
        while(j>=0)
        {
            int result=b[j]+0+carry;
            int digit=result%10;
            ans.push_back(digit+'0');
            carry=result/10;
            j--;
        }
        if(carry)
        {
            ans.push_back(carry+'0');
        }
        while(ans[ans.size()-1]=='0')
        {
            ans.pop_back();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }



    int main()
{
    int n;
    cout<<"Enter the size of first array: ";
    cin>>n;
    vector<int> v1(n);
    cout<<"Enter the element in the first array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    int m;
    cout<<"Enter the size of second array: ";
    cin>>m;
    vector<int> v2(m);
    cout<<"Enter the element in the second array: ";
    for(int i=0;i<m;i++)
    {
        cin>>v2[i];
    }
    cout<<AddTwoNumber(v1,n,v2,m);
   
    
}