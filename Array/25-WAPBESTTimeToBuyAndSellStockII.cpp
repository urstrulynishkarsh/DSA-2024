#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;




   int BUYANDSELLELEVEL2(vector<int>& prices) {
       int profit=0;
       for(int i=1;i<prices.size();i++)
       {
           profit+=max(0,prices[i]-prices[i-1]);
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
    cout<<BUYANDSELLELEVEL2(v);
   
    
}