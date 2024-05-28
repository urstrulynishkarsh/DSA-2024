#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

void twoRepeated(vector<int> &arr, int &N, vector<int> &ans)
{
    unordered_map<int,int> hash;
        for(int i=0;i<=N+1;i++)  //i<=N+1;
        {
            hash[arr[i]]++;
            if(hash[arr[i]]>1)
            {
                ans.push_back(arr[i]);
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
     twoRepeated(v,n,ans);
     for(auto val:ans)
     {
        cout<<val<<" ";
     }


}