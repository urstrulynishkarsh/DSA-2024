#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;




void MoveAllNeagiveToEnd(vector<int>& v) {
    vector<int> temp;
     for(int i=0;i<v.size();i++)
        {
            if(v[i]>=0)
            {
                temp.push_back(v[i]);
            }
        }
        for(int i=0;i<v.size();i++)
        {
            if(v[i]<0)
            {
                temp.push_back(v[i]);
            }
        }
      for(int i=0;i<v.size();i++)
        {
           v[i]=temp[i];
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
    MoveAllNeagiveToEnd(v);

   for(auto ele:v)
   {
    cout<<ele<<" ";
   }
    
}