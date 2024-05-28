#include<iostream>
#include<vector>
#include<set>
using namespace std;

int DiffentPair(vector<int> &nums,int k)
{
    sort(nums.begin(),nums.end());
    int i=0;
    int j=1;
    set<pair<int,int> > ans;
    while(j<nums.size())
    {
        int diff=nums[j]-nums[i];
        if(diff==k)
        {
            ans.insert({nums[i],nums[j]});
            i++;
            j++;
        }
        else if(diff>k)
        {
            i++;
        }
        else{
            j++;
        }
        if(i==j)
        {
            j++;
        }
    }
    return ans.size();
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
    cout<<"Enter the value: ";
    cin>>k;

    cout<<DiffentPair(v,k);

   
    
}