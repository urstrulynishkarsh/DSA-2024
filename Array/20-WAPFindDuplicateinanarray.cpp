#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;



void DuplicateInArray(vector<int>& v,vector<int> &ans) {
    vector<int> freq(v.size(),0);
    for(int i=0;i<v.size();i++)
    {
        freq[v[i]]++;
    }
    for(int i=0;i<v.size();i++)
    {
        if(freq[i]>1)
        {
            ans.push_back(i);
        }
    }
       
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
   vector<int> ans;
   DuplicateInArray(v,ans);

   for(auto ele:ans)
   {
    cout<<ele<<" ";
   }
   
    
}