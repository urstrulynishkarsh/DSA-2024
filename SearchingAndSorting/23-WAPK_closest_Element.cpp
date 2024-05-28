#include<iostream>
#include<vector>
#include<set>
using namespace std;

void KClosest(vector<int> &arr,int k,int x,vector<int> &ans)
{
   ;
        int s=0;
        int e=arr.size()-1;
        while(e-s>=k)
        {
            if(x-arr[s]>arr[e]-x)
            {
                s++;
            }
            else
            {
                e--;
            }
        }
        for(int i=s;i<=e;i++)
        {
            ans.push_back(arr[i]);
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

    int k;
    cout<<"Enter the how many value you want: ";
    cin>>k;

    int x;
    cout<<"Enter the element which you want to closest";
    cin>>x;
vector<int> ans;
    KClosest(v,k,x,ans);

    for(auto val: ans)
    {
        cout<<val<<" ";
    }


   
    
}