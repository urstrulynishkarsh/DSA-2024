#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
   int BUYANDSELLELEVEL1(vector<int>& prices) {
       int profit=0;
       int minimum=prices[0];
       for(int i=1;i<prices.size();i++)
       {
           int diff=prices[i]-minimum;
           profit=max(profit,diff);
           minimum=min(prices[i],minimum);
       }
       return profit;
    }



    int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int> v(n);
    cout<<"Enter the element in the array: ";
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    cout<<BUYANDSELLELEVEL1(v);
   
    
}